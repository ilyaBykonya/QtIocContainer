#pragma once
#include <QException>
#include <QString>


namespace QtIoc {
/*!
 * \brief The ElementNotStoredException exception
 * \details The container does not have a dependency with that name.
 */
class ElementNotStoredException : public QException {
private:
    QString m_description;
public:
    ElementNotStoredException(const QString& name);
    virtual const char *what() const override;
};
}
