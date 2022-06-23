#include "SharedContainer.h"

namespace QtIoc {
SharedContainer::SharedContainer(InstacneFactory factory)
    :m_factory{ std::move(factory) }
    {
    }

SharedContainer::~SharedContainer() {
    if(m_instance) { m_instance->deleteLater(); }
}

SharedContainer::InstancePointer SharedContainer::load() {
    if (m_instance.isNull()) {
        m_instance = m_factory();
    }

    return m_instance;
}
bool SharedContainer::contains() const {
    return (m_instance.isNull() == false) || static_cast<bool>(m_factory);
}
}
