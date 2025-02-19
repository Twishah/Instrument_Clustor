/* WARNING: AUTO-GENERATED FILE!
 * MANUAL EDITS WILL BE OVERWRITTEN BY "UPDATE PROJECT" IN LINX MANAGER PLUGIN.
 */

#include "fieldbusaccesserrormodel.h"

FieldbusAccessErrorModel::FieldbusAccessErrorModel(QObject *parent) : QAbstractTableModel(parent)
{
    Q_UNUSED(parent);
    m_errors = new QList<FieldbusAccessError*>();
    m_stackErrorCount = 0;
}

FieldbusAccessErrorModel::~FieldbusAccessErrorModel()
{

}

QHash<int, QByteArray> FieldbusAccessErrorModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[FieldbusAccessErrorModel::Bus] = "bus";
    roles[FieldbusAccessErrorModel::Level] = "level";
    roles[FieldbusAccessErrorModel::Code] = "code";
    roles[FieldbusAccessErrorModel::Identifier] = "identifier";
    roles[FieldbusAccessErrorModel::AddInfo] = "addInfo";
    roles[FieldbusAccessErrorModel::Description] = "description";
    roles[FieldbusAccessErrorModel::Started] = "started";
    roles[FieldbusAccessErrorModel::Ended] = "ended";
    roles[FieldbusAccessErrorModel::Exists] = "exists";

    return roles;
}

QVariant FieldbusAccessErrorModel::data(const QModelIndex &index, int role) const
{
    if (!(index.row() < m_errors->count() && index.column() < columnCount(index)))
        return QVariant();

    // Handle role types here, so that Error class can be unaware of model structure.
    FieldbusAccessError *error = m_errors->at(index.row());

    switch(role) {
    case FieldbusAccessErrorModel::Bus: return QVariant(error->bus());
    case FieldbusAccessErrorModel::Level: return QVariant(error->errorLevelToQString());
    case FieldbusAccessErrorModel::Code: return QVariant(error->ErrorCodeToString(error->code()));
    case FieldbusAccessErrorModel::Identifier: return QVariant(error->idToQString());
    case FieldbusAccessErrorModel::AddInfo: return QVariant(error->addInfoToQString());
    case FieldbusAccessErrorModel::Description: return QVariant(error->description());
    case FieldbusAccessErrorModel::Started: return QVariant(error->started());
    case FieldbusAccessErrorModel::Ended: return QVariant(error->ended());
    case FieldbusAccessErrorModel::Exists: return QVariant(error->errorExists());
    default: return QVariant();
    };

}

int FieldbusAccessErrorModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_errors->count();
}

int FieldbusAccessErrorModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return roleNames().count();
}

void FieldbusAccessErrorModel::addError(FieldbusAccessError *error)
{
    emit beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_errors->append(error);
    emit endInsertRows();
    emit errorAdded(error);
}

void FieldbusAccessErrorModel::addError(const QByteArray data, int bus)
{
    FieldbusAccessError *error = new FieldbusAccessError();
    error->setData(data);
    error->setBus(bus);

    int knownError = findError(error);

    if (knownError < 0) {
        // New error
        addError(error);
        if ((error->addInfo() == 0 || error->identifier() == FieldbusAccessError::MEM_ERR_ID) && (error->level() == FieldbusAccessError::ERROR || error->level() == FieldbusAccessError::FATAL))
            incStackErrors();
    }
    else {
        // Known error.
        FieldbusAccessError *existingError = m_errors->at(knownError);
        bool levelChanged = error->level() != existingError->level();
        bool infoChanged = error->addInfo() != existingError->addInfo();

        // Level changed?
        if (levelChanged) {
            FieldbusAccessError::ErrorLevel prevLevel = existingError->level();
            existingError->setLevel(error->level());
            if (existingError->level() == FieldbusAccessError::OK)
                emit errorCleared(existingError);

            if (error->addInfo() == 0 || error->identifier() == FieldbusAccessError::MEM_ERR_ID) {
                if ((prevLevel == FieldbusAccessError::ERROR || prevLevel == FieldbusAccessError::FATAL) &&
                        (error->level() == FieldbusAccessError::OK || error->level() == FieldbusAccessError::WARNING)) {
                    // One less stack error.
                    decStackErrors();
                }
                else if ((prevLevel == FieldbusAccessError::OK || prevLevel == FieldbusAccessError::WARNING) &&
                         (error->level() == FieldbusAccessError::ERROR || error->level() == FieldbusAccessError::FATAL)) {
                    // One less stack error.
                    incStackErrors();
                }

            }
        }

        // Info changed?
        if (infoChanged)
            existingError->setAddInfo(error->addInfo());

        // Emit changes
        if (levelChanged || infoChanged) {
            QVector<int> roles;

            if (levelChanged) {
                // Ensure all potentially affected fields are refreshed.
                roles.append(Level);
                roles.append(Started);
                roles.append(Ended);
                roles.append(Exists);
            }

            if (infoChanged)
                roles.append(AddInfo);

            emit dataChanged(createIndex(knownError,0),createIndex(knownError,0),roles);
        }

        // New error object was only used to update an existing error, and not stored. Destroy it.
        delete error;
     }
}

void FieldbusAccessErrorModel::setErrorOk(int row)
{
    if (!(row < m_errors->count()))
        return;

    m_errors->at(row)->setErrorExists(false);
    emit dataChanged(createIndex(row,0),createIndex(row,0),QVector<int>({Exists}));
}

void FieldbusAccessErrorModel::removeError(int row)
{
    if (!(row < m_errors->count()))
        return;

    if (m_errors->at(row)->addInfo() == 0 && (m_errors->at(row)->level() == FieldbusAccessError::ERROR || m_errors->at(row)->level() == FieldbusAccessError::FATAL))
        decStackErrors();
    emit errorCleared(m_errors->at(row));

    emit beginRemoveRows(QModelIndex(),row,row);
    delete m_errors->at(row);
    m_errors->removeAt(row);
    emit endRemoveRows();
}

bool FieldbusAccessErrorModel::stackError()
{
    return m_stackErrorCount > 0;
}

int FieldbusAccessErrorModel::findError(FieldbusAccessError *error)
{
    for (int i=0; i< m_errors->count(); ++i) {
        FieldbusAccessError *err = m_errors->at(i);
        if (err->level() != FieldbusAccessError::OK && err->code() == error->code() && err->identifier() == error->identifier() && err->addInfo() == error->addInfo())
            return i;
    }

    // Not found.
    return -1;
}

void FieldbusAccessErrorModel::incStackErrors()
{
    m_stackErrorCount++;
    if (m_stackErrorCount == 1)
        // Stack error now exist. Let the world know!
        emit stackErrorChanged(true);
}

void FieldbusAccessErrorModel::decStackErrors()
{
    m_stackErrorCount--;
    if (m_stackErrorCount < 1)
        // No more stack errors. Let the world know!
        emit stackErrorChanged(false);
}

