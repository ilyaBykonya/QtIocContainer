#pragma once
#include "../../QtIocContainer_global.h"
#include "../AbstractContainer/AbstractContainer.h"

namespace QtIoc {
/*!
 * \brief The SingletonContainer class
 * \details The base container class for the object,
 * providing singleton-lifetime.
 *
 * Singleton-lifetime:
 * One object for each call.
 */
class QTIOCCONTAINER_EXPORT SingletonContainer : public AbstractContainer {
private:
    using InstancePointer = typename AbstractContainer::QObjectPointer;
    InstancePointer m_instance;
public:
    SingletonContainer(InstancePointer instance);
    virtual ~SingletonContainer() override;
public:
    virtual InstancePointer load() override;
    virtual bool contains() const override;
};
}
