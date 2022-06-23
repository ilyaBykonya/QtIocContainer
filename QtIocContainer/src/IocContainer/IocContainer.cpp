#include "IocContainer.h"
#include "../Exceptions/ElementNotStoredException/ElementNotStoredException.h"
#include "../Exceptions/InvalidContainerException/InvalidContainerException.h"

namespace QtIoc {
IocContainer::IocContainer(QObject* parent)
    :QObject{ parent }
    {
    }

std::unordered_map<QString, IocContainer::ContainerPointer>::iterator IocContainer::takeIterator(const QString& name) {
    auto found_iter = m_instances.find(name);
    if (found_iter == m_instances.end())
        throw ElementNotStoredException{ name };

    return found_iter;
}
IocContainer::InstancePointer IocContainer::loadInstance(std::unordered_map<QString, ContainerPointer>::iterator iter) {
    InstancePointer instance = iter->second->load();
    if(instance.isNull())
        throw InvalidContainerException{ iter->first };

    return instance;
}

void IocContainer::store_dependency(const QString& name, ContainerPointer container) {
    m_instances[name] = std::move(container);
}
QPointer<QObject> IocContainer::load_dependency(const QString& name) {
    return loadInstance(takeIterator(name));
}
void IocContainer::remove_dependency(const QString &name) {
    m_instances.erase(name);
}
}
