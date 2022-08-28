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
 * \details CRUD-repository for storing containers with objects.
 */
class IocContainer : public QObject {
private:
    using ContainerPointer = QSharedPointer<AbstractContainer>;
    using ContainerStorage = std::unordered_map<std::type_index, ContainerPointer>;
    using ContainerStorageIterator = ContainerStorage::iterator;

    std::unordered_map<std::type_index, ContainerPointer> m_instances;
private:
    template<typename Type>
    ContainerStorageIterator takeIterator() {
        auto found_iter = m_instances.find({ typeid(Type) });
        if (found_iter == m_instances.end())
            throw ElementNotStoredException<Type>{};

        return found_iter;
    }
    template<typename Type>
    QPointer<Type> loadInstance(ContainerStorageIterator iter) {
        auto instance = iter->second->load();
        return qobject_cast<Type*>(instance);
    }
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
    void store_dependency(ContainerPointer container) {
        m_instances[{ typeid(Type) }] = container;
    }
    /*!
     * \brief load_dependency
     * \return object-instance
     * \param dependency-name
     * \details Load instace from storage
     */
    template<typename Type>
    QPointer<Type> load_dependency() {
        return loadInstance<Type>(takeIterator<Type>());
    }
    /*!
     * \brief remove_dependency
     * \return void
     * \param dependency-name
     * \details Remove instace from storage
     */
    template<typename Type>
    void remove_dependency() {
        m_instances.erase({ typeid(Type) });
    }
};


}
