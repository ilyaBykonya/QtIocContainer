#pragma once
#include "../../QtIocContainer_global.h"
#include <QException>
#include <QString>


namespace QtIoc {
/*!
 * \brief The ElementNotStoredException exception
 *
 * \details Выбрасывается, когда в контейнере нет зависимости нужного элемента.
 */
class QTIOCCONTAINER_EXPORT FailedIntanceCastOnLoadException : public QException {
private:
    QString m_description;
public:
    FailedIntanceCastOnLoadException(const QString& name);
    virtual const char *what() const override;
};
}

