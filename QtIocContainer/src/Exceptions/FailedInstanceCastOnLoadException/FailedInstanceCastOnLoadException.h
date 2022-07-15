#pragma once
#include <QException>
#include <QString>


namespace QtIoc {
/*!
 * \brief The FailedInstanceCastOnLoadException exception
 * \details The instance could not be converted to the required type
 */
class FailedInstanceCastOnLoadException : public QException {
public:
    FailedInstanceCastOnLoadException(const QString& name);
    virtual const char *what() const override;
};
}


