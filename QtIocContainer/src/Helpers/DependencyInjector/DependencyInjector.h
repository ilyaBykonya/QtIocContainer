#pragma once
#include "../../IocContainer/IocContainer.h"
#include <QMetaMethod>

namespace QtIoc {
/*!
 * \brief The DependencyInjector class
 */
class DependencyInjector {
private:
    QPointer<IocContainer> m_container;
public:
    DependencyInjector(QPointer<IocContainer> container);

    /*!
     * \brief inject_dependencies
     * \param QPointer<Type> intance
     * \return void
     */
    void inject_dependencies(QPointer<QObject> object);
    /*!
     * \brief inject_dependencies
     * \param Type* intance
     * \return void
     */
    void inject_dependencies(QObject* object);
private:
    QList<QMetaMethod> select_inject_methods(const QMetaObject* meta_info);
    void call_inject_methods(void* object, QList<QMetaMethod> injectors);
};
}


