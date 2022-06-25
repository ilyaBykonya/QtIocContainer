#pragma once
#include <QException>
#include <QString>


namespace QtIoc {
/*!
 * \brief The FailedIntanceCastOnLoadException exception
 * \details The instance could not be converted to the required type
 */
class FailedIntanceCastOnLoadException : public QException {
private:
    QString m_description;
public:
    FailedIntanceCastOnLoadException(const QString& name);
    virtual const char *what() const override;
};
}


