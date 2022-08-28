#pragma once
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
public:
    DependencyLoader()
        :m_container{ IocContainer::instance() }
        {
        }
    DependencyLoader(QPointer<IocContainer> container)
        :m_container{ container }
        {
        }

    /*!
     * \brief load ()
     * \details Loads an instance of an object from a container and injects dependencies into it.
     * \return QPointer<Type>
     * \throw ElementNotStoredException
     */
    QPointer<Type> load() {
        QPointer<Type> instance = m_container->load_dependency<Type>();
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
public:
    DependencyLoader()
        :m_container{ IocContainer::instance() }
        {
        }
    DependencyLoader(QPointer<IocContainer> container)
        :m_container{ container }
        {
        }

    /*!
     * \brief load ()
     * \details Loads an instance of an object from a container and injects dependencies into it.
     * \return QPointer<Type>
     * \throw ElementNotStoredException
     */
    QPointer<Type> load() {
        QPointer<Type> instance = m_container->load_dependency<Type>();
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
public:
    DependencyLoader()
        :m_container{ IocContainer::instance() }
        {
        }
    DependencyLoader(QPointer<IocContainer> container)
        :m_container{ container }
        {
        }


    /*!
     * \brief load ()
     * \details Loads an instance of an object from a container and injects dependencies into it.
     * \return QPointer<Type>
     * \throw ElementNotStoredException
     */
    QPointer<Type> load() {
        QPointer<Type> instance = m_container->load_dependency<Type>();
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
