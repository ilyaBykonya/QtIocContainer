#pragma once
#include "../../QtDependencyInjection_global.h"
#include <QException>
#include <QString>


namespace QtIoc {
/*!
 * \brief The InvalidContainerException exception
 * \details AbstractContainer did not return an element
 */
class QTDEPENDENCYINJECTION_EXPORT InvalidContainerException : public QException {
private:
    QString m_description;
public:
    InvalidContainerException(const QString& name);
    virtual const char *what() const override;
};
}



