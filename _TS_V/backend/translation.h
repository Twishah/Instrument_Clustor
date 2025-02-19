#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QtGui>
#include <QString>
#include <QStringList>
#include <QCoreApplication>

class TranslationHandler : public QObject
{
 Q_OBJECT
 Q_PROPERTY(QString emptyString READ getEmptyString NOTIFY languageChanged)

 public:

    Q_INVOKABLE QString trad_multiple_labels(QString labels) {

        QStringList idList = labels.split("\n");

        for (int i = 0; i < idList.size(); ++i) {
            // Ici, nous utilisons un contexte vide et l'ID de chaîne comme clé de traduction
            idList[i] = QCoreApplication::translate("", idList[i].toUtf8().constData());
        }
        QString translatedMultiLine = idList.join("\n");

        return translatedMultiLine;
    }

  TranslationHandler() {
   translator1 = new QTranslator(this);
  }

  QString getEmptyString() {
   return "";
  }

 Q_INVOKABLE void selectLanguage(QString language) {
    if(language == QString("fr")) {
        locale = QLocale(QLocale::French, QLocale::France) ;
        qDebug() << locale;
    }

    if(language == QString("es")) {
        locale = QLocale(QLocale::Spanish, QLocale::Spain) ;
        qDebug() << locale;
    }

    if(language == QString("fi")) {
        locale = QLocale(QLocale::Finnish, QLocale::Finland) ;
        qDebug() << locale;
    }

    if(language == QString("en")) {
      locale = QLocale(QLocale::English, QLocale::UnitedStates) ;
      qDebug() << locale;
    }
    if(language == QString("pl")) {
        locale = QLocale(QLocale::Polish, QLocale::Poland) ;
        qDebug() << locale;
    }

    if(language == QString("it")) {
        locale = QLocale(QLocale::Italian, QLocale::Italy) ;
        qDebug() << locale;
    }

    if(language == QString("pt")) {
      locale = QLocale(QLocale::Portuguese, QLocale::Brazil) ;
      qDebug() << locale;
    }
    if(language == QString("sv")) {
        locale = QLocale(QLocale::Swedish, QLocale::Sweden) ;
        qDebug() << locale;
    }

    if(language == QString("de")) {
        locale = QLocale(QLocale::German, QLocale::Germany) ;
        qDebug() << locale;
    }

    if(language == QString("nl")) {
      locale = QLocale(QLocale::Dutch, QLocale::Netherlands) ;
      qDebug() << locale;
    }

    if(language == QString("da")) {
      locale = QLocale(QLocale::Danish, QLocale::Denmark) ;
      qDebug() << locale;
    }

    if(translator1->load(locale, QLatin1String("fmc_hmi"), QLatin1String("_"), QLatin1String("/opt/fmc_hmi/Linguist"))) {
    //if(translator1->load(locale, QLatin1String("fmc_hmi"), QLatin1String("_"), QLatin1String("/media/sf_Shared/T-S-YANMA-23-501700_HMI_FMC_MX_BE2/Linguist"))) { // PC emulation
        if(qApp->installTranslator(translator1)){
            qDebug() << "Language loaded";
        } else {
                qDebug() << "Translator error";
        }
    }else {
        qDebug() << "Translator error";
    }
    emit languageChanged();
  }

 signals:
  void languageChanged();

 private:
  QTranslator *translator1;
  QLocale locale ;
};

#endif // TRANSLATION_H
