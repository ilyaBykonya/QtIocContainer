#pragma once
#include "../IocContainer/IocContainer.h"
#include <QMetaMethod>
#include <type_traits>

namespace QtIoc {
/*!
 * \brief The DependencyInjector class
 * \details Инъектор зависимостей. Даёт контейнер для загрузки всем зависимостям объекта.
 */
class DependencyInjector {
private:
    QPointer<IocContainer> m_container;
public:
    DependencyInjector(QPointer<IocContainer> container)
        :m_container{ container }
        {
        }
    template<typename Type>
    void inject_dependencies(QPointer<Type> object) {
        call_inject_methods(object, select_inject_methods(object->metaObject()));
    }
    template<typename Type>
    void inject_dependencies(Type* object) {
        call_inject_methods(object, select_inject_methods(object->metaObject()));
    }

private:
    QList<QMetaMethod> select_inject_methods(const QMetaObject* meta_info) {
        QList<QMetaMethod> result;
        for(int index = 0; index < meta_info->methodCount(); ++index) {
            auto method_info = meta_info->method(index);
            if(method_info.name().startsWith("inject_") == false)
                continue;

            auto params = method_info.parameterTypes();
            if(params.size() != 1)
                continue;
            if(params.first() != "QPointer<QtIoc::IocContainer>")
                continue;

            result.push_back(method_info);
        }
        return result;
    }
    void call_inject_methods(void* object, QList<QMetaMethod> injectors) {
        for(auto injector: injectors)
            injector.invokeOnGadget(object, Q_ARG(QPointer<QtIoc::IocContainer>, m_container));
    }
};
}
