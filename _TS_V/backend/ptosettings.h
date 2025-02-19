#ifndef PTOSETTINGS_H
#define PTOSETTINGS_H

/******************************************************************************
 * Include Files
******************************************************************************/
#include <QObject>
#include <QtQml>

/******************************************************************************
 * Class Declaration
******************************************************************************/
/*
 * The flow limit settings
 * structure
 */

class Flow_limit_acc : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString accessory_icon_source READ accessory_icon_source WRITE set_accessory_icon_source NOTIFY accessory_icon_sourceChanged)
    Q_PROPERTY(int pto1_left READ pto1_left WRITE set_pto1_left)
    Q_PROPERTY(int pto1_right READ pto1_right WRITE set_pto1_right)
    Q_PROPERTY(int pto2_left READ pto2_left WRITE set_pto2_left)
    Q_PROPERTY(int pto2_right READ pto2_right WRITE set_pto2_right)

public:

    explicit Flow_limit_acc(QObject *parent = 0);

    QString accessory_icon_source();
    int pto1_left();
    int pto1_right();
    int pto2_left();
    int pto2_right();

    void set_accessory_icon_source(QString accessory_icon_source);
    void set_pto1_left(int pto1_left);
    void set_pto1_right(int pto1_right);
    void set_pto2_left(int pto2_left);
    void set_pto2_right(int pto2_right);

signals:
    void accessory_icon_sourceChanged(QString accessory_icon_source);

private:
    QString m_accessory_icon_source;
    int m_pto1_left;
    int m_pto1_right;
    int m_pto2_left;
    int m_pto2_right;
};

#endif // PTOSETTINGS_H
