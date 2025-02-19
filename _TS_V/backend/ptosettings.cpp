
#include "ptosettings.h"

Flow_limit_acc::Flow_limit_acc(QObject *parent)
{
    setParent(parent);

    m_accessory_icon_source = "";
    m_pto1_left = 10;
    m_pto1_right = 10;
    m_pto2_left = 10;
    m_pto2_right = 10;
}

/**
* @brief Gets the accessory icon source.
* @return The source path to the accessory icon.
*/
QString Flow_limit_acc::accessory_icon_source() { return m_accessory_icon_source; }

/**
* @brief Gets the PTO 1 left setting
* @return The value for PTO 1 left setting
*/
int Flow_limit_acc::pto1_left()
{
    return m_pto1_left;
}

/**
* @brief Gets the PTO 1 right setting
* @return The value for PTO 1 right setting
*/
int Flow_limit_acc::pto1_right() { return m_pto1_right; }

/**
* @brief Gets the PTO 2 left setting
* @return The value for PTO 2 left setting
*/
int Flow_limit_acc::pto2_left() { return m_pto2_left; }

/**
* @brief Gets the PTO 2 right setting
* @return The value for PTO 2 right setting
*/
int Flow_limit_acc::pto2_right() { return m_pto2_right; }

/**
* @brief Sets the accessory icon source.
*/
void Flow_limit_acc::set_accessory_icon_source(QString accessory_icon_source)
{
    m_accessory_icon_source = accessory_icon_source;
    emit accessory_icon_sourceChanged(m_accessory_icon_source);
}

/**
* @brief Sets the PTO 1 left setting
*/
void Flow_limit_acc::set_pto1_left(int pto1_left)
{
    m_pto1_left = pto1_left;
}

/**
* @brief Sets the PTO 1 right setting
*/
void Flow_limit_acc::set_pto1_right(int pto1_right)
{
    m_pto1_right = pto1_right;
}

/**
* @brief Sets the PTO 2 left setting
*/
void Flow_limit_acc::set_pto2_left(int pto2_left)
{
    m_pto2_left = pto2_left;
}

/**
* @brief Sets the PTO 2 right setting
*/
void Flow_limit_acc::set_pto2_right(int pto2_right)
{
    m_pto2_right = pto2_right;
}
