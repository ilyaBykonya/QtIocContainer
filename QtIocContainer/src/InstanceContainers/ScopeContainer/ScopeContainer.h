#pragma once
#include "../AbstractContainer/AbstractContainer.h"
#include <functional>


namespace QtIoc {
/*!
 * \brief The ScopeContainer class
 * \details The base container class for the object,
 * providing scope-lifetime.
 *
 * Scope-lifetime:
 * a new object is created for each call.
 */
class ScopeContainer : public AbstractContainer {
private:
    using InstancePointer = typename AbstractContainer::QObjectPointer;
    using InstanceFactory = std::function<InstancePointer()>;
    InstanceFactory m_factory;
public:
    ScopeContainer(InstanceFactory factory);
    virtual InstancePointer load() override;
    virtual bool contains() const override;
};
}

