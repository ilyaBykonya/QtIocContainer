#pragma once

#define Q_INJECT_IN_DEFAULT(Type, Name) \
    QPointer<Type> m_##Name; \
    Q_INVOKABLE void inject_##Name(QPointer<QtIoc::IocContainer> container) { \
        auto loaded = QtIoc::DependencyLoader<Type>{ container, #Name }.load(); \
        if(loaded != m_##Name) { \
            m_##Name = QtIoc::DependencyLoader<Type>{ container, #Name }.load(); \
        }\
    }

#define Q_INJECT_IN_MEMBER(Type, Name, Member) \
    Q_INVOKABLE void inject_##Name(QPointer<QtIoc::IocContainer> container) { \
        auto loaded = QtIoc::DependencyLoader<Type>{ container, #Name }.load(); \
        if(loaded != ##Member) { \
            ##Member = loaded; \
        }\
    }

#define Q_INJECT_IN_METHOD(Type, Name, Method) \
    Q_INVOKABLE void inject_##Name(QPointer<QtIoc::IocContainer> container) { \
        ##Method(QtIoc::DependencyLoader<Type>{ container, #Name }.load()); \
    }

