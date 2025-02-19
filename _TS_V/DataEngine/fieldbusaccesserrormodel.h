/* WARNING: AUTO-GENERATED FILE!
 * MANUAL EDITS WILL BE OVERWRITTEN BY "UPDATE PROJECT" IN LINX MANAGER PLUGIN.
 */

#ifndef FIELDBUSACCESSERRORMODEL_H
#define FIELDBUSACCESSERRORMODEL_H

#include <QAbstractTableModel>
#include "fieldbusaccesserror.h"

class FieldbusAccessErrorModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(bool stackError READ stackError NOTIFY stackErrorChanged)

public:
    explicit FieldbusAccessErrorModel(QObject *parent=0);
    ~FieldbusAccessErrorModel();

    enum DataRoles {
        Bus,
        Level,
        Code,
        Identifier,
        AddInfo,
        Description,
        Started,
        Ended,
        Exists
    };
    QHash<int, QByteArray> roleNames() const;

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    void addError(FieldbusAccessError* error);
    void addError(const QByteArray data, int bus = 0);
    void setErrorOk(int row); // NOTE: Is this one ever used?
    Q_INVOKABLE void removeError(int row);
    bool stackError();

signals:
    void errorAdded(FieldbusAccessError* error);
    void errorCleared(FieldbusAccessError *error);
    //void allStackErrorsCleared();
    void stackErrorChanged(bool exist);

private:
    int findError(FieldbusAccessError *error);
    void incStackErrors();
    void decStackErrors();


    QList<FieldbusAccessError*> *m_errors;
    int m_stackErrorCount;
};

#endif // FIELDBUSACCESSERRORMODEL_H
