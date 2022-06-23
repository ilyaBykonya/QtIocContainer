#include "SingletonContainer.h"

namespace QtIoc {
SingletonContainer::SingletonContainer(InstancePointer instance)
    :m_instance{ std::move(instance) }
    {
    }
SingletonContainer::~SingletonContainer() {
    if(m_instance) { m_instance->deleteLater(); }
}

SingletonContainer::InstancePointer SingletonContainer::load() {
    return m_instance;
}
bool SingletonContainer::contains() const {
    return static_cast<bool>(m_instance);
}
}
