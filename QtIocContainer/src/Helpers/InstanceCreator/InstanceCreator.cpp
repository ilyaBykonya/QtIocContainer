#include "InstanceCreator.h"


namespace QtIoc {
InstanceCreator::InstanceCreator()
    :m_container{ IocContainer::instance() }
    {
    }
InstanceCreator::InstanceCreator(QPointer<IocContainer> container)
    :m_container{ std::move(container) }
    {
    }
}
