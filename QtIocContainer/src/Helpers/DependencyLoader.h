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
    DependencyLoader() = default;
    DependencyLoader(const QString& name)
        :m_name{ name }
        {
        }
    DependencyLoader(QPointer<IocContainer> container)
        :m_container{ container }
        {
        }
    DependencyLoader(QPointer<IocContainer> container, const QString& name)
        :m_container{ container },
         m_name{ name }
        {
        }

    void setContainer(QPointer<IocContainer> container) {
        m_container = container;
    }
    void serName(const QString& name) {
        m_name = name;
    }

    /*!
     * \brief load ()
     * \return std::shared_ptr<Type>
     * \throw ElementNotStoredException Если зависиммости нет в контейнере
     * \throw InvalidContainerException При внутренней ошибке
     * \throw FailedIntanceCastOnLoadException При невозможности преобразования типа
     * \throw std::bad_any_cast При внутренней ошибке
     */
    QPointer<Type> load() {
        QPointer<Type> instance{ qobject_cast<Type*>(m_container->load_dependency(m_name)) };
        if(instance.isNull())
            throw FailedIntanceCastOnLoadException{ typeid(Type).name() };

        DependencyInjector{ m_container }.inject_dependencies(instance);
        return instance;
    }
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
    DependencyLoader() = default;
    DependencyLoader(const QString& name)
        :m_name{ name }
        {
        }
    DependencyLoader(QPointer<IocContainer> container)
        :m_container{ container }
        {
        }
    DependencyLoader(QPointer<IocContainer> container, const QString& name)
        :m_container{ container },
         m_name{ name }
        {
        }

    void setContainer(QPointer<IocContainer> container) {
        m_container = container;
    }
    void serName(const QString& name) {
        m_name = name;
    }

    /*!
     * \brief load ()
     * \return std::shared_ptr<Type>
     * \throw ElementNotStoredException Если зависиммости нет в контейнере
     * \throw InvalidContainerException При внутренней ошибке
     * \throw FailedIntanceCastOnLoadException При невозможности преобразования типа
     * \throw std::bad_any_cast При внутренней ошибке
     */
    QPointer<Type> load() {
        QPointer<Type> instance{ qobject_cast<Type*>(m_container->load_dependency(m_name)) };
        if(instance.isNull())
            throw FailedIntanceCastOnLoadException{ typeid(Type).name() };

        DependencyInjector{ m_container }.inject_dependencies(instance);
        return instance;
    }
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
    DependencyLoader() = default;
    DependencyLoader(const QString& name)
        :m_name{ name }
        {
        }
    DependencyLoader(QPointer<IocContainer> container)
        :m_container{ container }
        {
        }
    DependencyLoader(QPointer<IocContainer> container, const QString& name)
        :m_container{ container },
         m_name{ name }
        {
        }

    void setContainer(QPointer<IocContainer> container) {
        m_container = container;
    }
    void serName(const QString& name) {
        m_name = name;
    }

    /*!
     * \brief load ()
     * \return std::shared_ptr<Type>
     * \throw ElementNotStoredException Если зависиммости нет в контейнере
     * \throw InvalidContainerException При внутренней ошибке
     * \throw FailedIntanceCastOnLoadException При невозможности преобразования типа
     * \throw std::bad_any_cast При внутренней ошибке
     */
    QPointer<Type> load() {
        QPointer<Type> instance{ qobject_cast<Type*>(m_container->load_dependency(m_name)) };
        if(instance.isNull())
            throw FailedIntanceCastOnLoadException{ typeid(Type).name() };

        DependencyInjector{ m_container }.inject_dependencies(instance);
        return instance;
    }
    QPointer<Type> operator->() {
        return this->load();
    }
};


}

