#include "ScopeContainer.h"

namespace QtIoc {
ScopeContainer::ScopeContainer(InstanceFactory factory)
    :m_factory{ std::move(factory) }
    {
    }

ScopeContainer::InstancePointer ScopeContainer::load() {
    return m_factory();
}
bool ScopeContainer::contains() const {
    return static_cast<bool>(m_factory);
}
}
