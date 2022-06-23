#pragma once
#include "../InstanceContainers/AbstractContainer/AbstractContainer.h"
#include "../QtIocContainer_global.h"
#include <unordered_map>
#include <type_traits>
#include <string>

namespace QtIoc {
class QTIOCCONTAINER_EXPORT IocContainer : public QObject {
private:
    using InstancePointer = QPointer<QObject>;
    using InstanceFactory = std::function<InstancePointer()>;
    using ContainerPointer = std::shared_ptr<AbstractContainer>;

    std::unordered_map<QString, ContainerPointer> m_instances;
private:
    std::unordered_map<QString, ContainerPointer>::iterator takeIterator(const QString& name);
    InstancePointer loadInstance(std::unordered_map<QString, ContainerPointer>::iterator iter);
public:
    explicit IocContainer(QObject* parent = nullptr);

    /*!
     * \brief store_dependency
     * \param dependency-name и dependency-container
     * \details Store instance-container into storage
     */
    void store_dependency(const QString& name, ContainerPointer container);
    /*!
     * \brief load_dependency
     * \return object-instance
     * \param dependency-name
     * \details Load instace from storage
     */
    QPointer<QObject> load_dependency(const QString& name);
};
}