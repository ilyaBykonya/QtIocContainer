#include "DependencyInjector.h"

namespace QtIoc {
DependencyInjector::DependencyInjector()
    :m_container{ IocContainer::instance() }
    {
    }
DependencyInjector::DependencyInjector(QPointer<IocContainer> container)
    :m_container{ container }
    {
    }

void DependencyInjector::inject_dependencies(QPointer<QObject> object) {
    call_inject_methods(object, select_inject_methods(object->metaObject()));
}
void DependencyInjector::inject_dependencies(QObject* object) {
    call_inject_methods(object, select_inject_methods(object->metaObject()));
}

QList<QMetaMethod> DependencyInjector::select_inject_methods(const QMetaObject* meta_info) {
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
void DependencyInjector::call_inject_methods(void* object, QList<QMetaMethod> injectors) {
    for(auto injector: injectors)
        injector.invokeOnGadget(object, Q_ARG(QPointer<QtIoc::IocContainer>, m_container));
}
}



