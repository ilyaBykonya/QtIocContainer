#pragma once
#include "../../Exceptions/FailedInstanceCastOnLoadException/FailedInstanceCastOnLoadException.h"
#include "../DependencyInjector/DependencyInjector.h"
#include <stdexcept>
#include <memory>

namespace QtIoc {

/*!
 * \brief The DependenciesLoader class
 *
 * \details Class for loading a dependency from a container.
 */
template<typename Type>
class DependencyLoader;

template<typename Type>
class DependencyLoader {
private:
    QPointer<IocContainer> m_container;
    QString m_name;
public:
    DependencyLoader(const QString& name)
        :m_container{ IocContainer::instance() },
         m_name{ name }
        {
        }
    DependencyLoader(QPointer<IocContainer> container, const QString& name)
        :m_container{ container },
         m_name{ name }
        {
        }

    /*!
     * \brief load ()
     * \details Loads an instance of an object from a container and injects dependencies into it.
     * \return QPointer<Type>
     * \throw ElementNotStoredException
     * \throw InvalidContainerException
     * \throw FailedInstanceCastOnLoadException
     */
    QPointer<Type> load() {
        QPointer<Type> instance{ qobject_cast<Type*>(m_container->load_dependency(m_name)) };
        if(instance.isNull())
            throw FailedInstanceCastOnLoadException{ typeid(Type).name() };

        DependencyInjector{ m_container }.inject_dependencies(instance);
        return instance;
    }
    /*!
     * \brief operator ->
     * \return QPointer<Type>
     * \details Wrapper over load() for direct access to the instance.
     */
    QPointer<Type> operator->() {
        return this->load();
    }
};

template<typename Type>
class DependencyLoader<Type*> {
private:
    QPointer<IocContainer> m_container;
    QString m_name;
public:
    DependencyLoader(const QString& name)
        :m_container{ IocContainer::instance() },
         m_name{ name }
        {
        }
    DependencyLoader(QPointer<IocContainer> container, const QString& name)
        :m_container{ container },
         m_name{ name }
        {
        }

    /*!
     * \brief load ()
     * \details Loads an instance of an object from a container and injects dependencies into it.
     * \return QPointer<Type>
     * \throw ElementNotStoredException
     * \throw InvalidContainerException
     * \throw FailedInstanceCastOnLoadException
     */
    QPointer<Type> load() {
        QPointer<Type> instance{ qobject_cast<Type*>(m_container->load_dependency(m_name)) };
        if(instance.isNull())
            throw FailedInstanceCastOnLoadException{ typeid(Type).name() };

        DependencyInjector{ m_container }.inject_dependencies(instance);
        return instance;
    }
    /*!
     * \brief operator ->
     * \return QPointer<Type>
     * \details Wrapper over load() for direct access to the instance.
     */
    QPointer<Type> operator->() {
        return this->load();
    }
};

template<typename Type>
class DependencyLoader<QPointer<Type>> {
private:
    QPointer<IocContainer> m_container;
    QString m_name;
public:
    DependencyLoader(const QString& name)
        :m_container{ IocContainer::instance() },
         m_name{ name }
        {
        }
    DependencyLoader(QPointer<IocContainer> container, const QString& name)
        :m_container{ container },
         m_name{ name }
        {
        }


    /*!
     * \brief load ()
     * \details Loads an instance of an object from a container and injects dependencies into it.
     * \return QPointer<Type>
     * \throw ElementNotStoredException
     * \throw InvalidContainerException
     * \throw FailedInstanceCastOnLoadException
     */
    QPointer<Type> load() {
        QPointer<Type> instance{ qobject_cast<Type*>(m_container->load_dependency(m_name)) };
        if(instance.isNull())
            throw FailedInstanceCastOnLoadException{ typeid(Type).name() };

        DependencyInjector{ m_container }.inject_dependencies(instance);
        return instance;
    }
    /*!
     * \brief operator ->
     * \return QPointer<Type>
     * \details Wrapper over load() for direct access to the instance.
     */
    QPointer<Type> operator->() {
        return this->load();
    }
};
}
