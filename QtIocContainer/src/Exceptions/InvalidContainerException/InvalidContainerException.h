#pragma once
#include <QException>
#include <QString>


namespace QtIoc {
/*!
 * \brief The InvalidContainerException exception
 * \details AbstractContainer did not return an element
 */
class InvalidContainerException : public QException {
private:
    QString m_description;
public:
    InvalidContainerException(const QString& name);
    virtual const char *what() const override;
};
}



