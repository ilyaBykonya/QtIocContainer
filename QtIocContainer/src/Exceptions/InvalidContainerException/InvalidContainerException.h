#pragma once
#include "../../QtIocContainer_global.h"
#include <QException>
#include <QString>


namespace QtIoc {
/*!
 * \brief The InvalidContainerException exception
 *
 * \details Внутренняя ошибка библиотеки.
 * В теории не может быть выброшена в принципе.
 */
class QTIOCCONTAINER_EXPORT InvalidContainerException : public QException {
private:
    QString m_description;
public:
    InvalidContainerException(const QString& name);
    virtual const char *what() const override;
};
}



