#include "InstanceCaller.h"

namespace QtIoc {
InstanceCaller::InstanceCaller()
    :m_container{ IocContainer::instance() }
    {
    }
InstanceCaller::InstanceCaller(QPointer<IocContainer> container)
    :m_container{ std::move(container) }
    {
    }
}
