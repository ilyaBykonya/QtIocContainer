#pragma once
#include "../../QtDependencyInjection_global.h"
#include <QException>
#include <QString>


namespace QtIoc {
/*!
 * \brief The ElementNotStoredException exception
 * \details The instance could not be converted to the required type
 */
class QTDEPENDENCYINJECTION_EXPORT FailedIntanceCastOnLoadException : public QException {
private:
    QString m_description;
public:
    FailedIntanceCastOnLoadException(const QString& name);
    virtual const char *what() const override;
};
}


