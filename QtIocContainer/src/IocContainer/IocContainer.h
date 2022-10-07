#pragma once
#include "../Exceptions/ElementNotStoredException/ElementNotStoredException.h"
#include "../InstanceContainers/AbstractContainer/AbstractContainer.h"
#include <QSharedPointer>
#include <unordered_map>
#include <type_traits>
#include <typeindex>

namespace QtIoc {
/*!
 * \brief The IocContainer class
 * \details Repository for storing containers with objects.
 */
class IocContainer : public QObject {
private:
    using ContainerPointer = QSharedPointer<AbstractContainer>;
    using ContainerStorage = std::unordered_map<std::type_index, std::map<QString, ContainerPointer>>;
    ContainerStorage m_instances;
public:
    explicit IocContainer(QObject* parent = nullptr)
        :QObject{ parent }
        {
        }
    static QPointer<IocContainer> instance() {
        static QPointer<IocContainer> instance{ new IocContainer };
        return instance;
    }

    /*!
     * \brief store_dependency
     * \param dependency-name и dependency-container
     * \details Store instance-container into storage
     */
    template<typename Type>
    void store_dependency(const QString& name = {}, ContainerPointer container = {}) {
        m_instances[{ typeid(Type) }][name] = container;
    }
    /*!
     * \brief load_dependency
     * \return object-instance
     * \param dependency-name
     * \details Load instace from storage
     */
    template<typename Type>
    QPointer<Type> load_dependency(const QString& name = {}) {
        auto type_iter = m_instances.find(std::type_index{ typeid(Type) });
        if(type_iter == m_instances.end())
            throw ElementNotStoredException<Type>{};
        auto name_iter = type_iter->second.find(name);
        if(name_iter == type_iter->second.end())
            throw ElementNotStoredException<Type>{};
        if(name_iter->second.isNull()) {
            type_iter->second.erase(name_iter);
            if(type_iter->second.empty()) {
                m_instances.erase(type_iter);
            }
            throw ElementNotStoredException<Type>{};
        }
        return qobject_cast<Type*>(name_iter->second->load());
    }
    /*!
     * \brief remove_dependency
     * \return void
     * \param dependency-name
     * \details Remove instace from storage
     */
    template<typename Type>
    void remove_dependency(const QString& name = {}) {
        const auto type = std::type_index{ typeid(Type) };
        m_instances[type].erase(name);
        if(m_instances[type].empty())
            m_instances.erase(type);
    }
};


}
