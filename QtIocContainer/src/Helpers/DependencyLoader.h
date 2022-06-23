#pragma once
#include "../Exceptions/FailedIntanceCastOnLoadException/FailedIntanceCastOnLoadException.h"
#include "DependencyInjector.h"
#include <stdexcept>
#include <memory>
#include <any>

namespace QtIoc {

/*!
 * \brief The DependenciesLoader class
 *
 * \details Класс для загрузки зависимости из контейнера.
 */
template<typename Type>
class DependencyLoader;

template<typename Type>
class DependencyLoader {
private:
    QPointer<IocContainer> m_container;
    QString m_name;
public:
    DependencyLoader(QPointer<IocContainer> container, const QString& name)
        :m_container{ container },
         m_name{ name }
        {
        }

    /*!
     * \brief load ()
     * \details Загружает инстанс объекта из контейнера и внедряет в него зависимости.
     * \return QPointer<Type>
     * \throw ElementNotStoredException
     * \throw InvalidContainerException
     * \throw FailedIntanceCastOnLoadException
     */
    QPointer<Type> load() {
        QPointer<Type> instance{ qobject_cast<Type*>(m_container->load_dependency(m_name)) };
        if(instance.isNull())
            throw FailedIntanceCastOnLoadException{ typeid(Type).name() };

        DependencyInjector{ m_container }.inject_dependencies(instance);
        return instance;
    }
    /*!
     * \brief operator ->
     * \return QPointer<Type>
     * \details Обёртка над load() для прямого доступа к инстансу.
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
    DependencyLoader(QPointer<IocContainer> container, const QString& name)
        :m_container{ container },
         m_name{ name }
        {
        }

    /*!
     * \brief load ()
     * \details Загружает инстанс объекта из контейнера и внедряет в него зависимости.
     * \return QPointer<Type>
     * \throw ElementNotStoredException
     * \throw InvalidContainerException
     * \throw FailedIntanceCastOnLoadException
     */
    QPointer<Type> load() {
        QPointer<Type> instance{ qobject_cast<Type*>(m_container->load_dependency(m_name)) };
        if(instance.isNull())
            throw FailedIntanceCastOnLoadException{ typeid(Type).name() };

        DependencyInjector{ m_container }.inject_dependencies(instance);
        return instance;
    }
    /*!
     * \brief operator ->
     * \return QPointer<Type>
     * \details Обёртка над load() для прямого доступа к инстансу.
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
     * \throw FailedIntanceCastOnLoadException
     */
    QPointer<Type> load() {
        QPointer<Type> instance{ qobject_cast<Type*>(m_container->load_dependency(m_name)) };
        if(instance.isNull())
            throw FailedIntanceCastOnLoadException{ typeid(Type).name() };

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

