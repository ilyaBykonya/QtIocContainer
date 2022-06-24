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
class QTDEPENDENCYINJECTION_EXPORT ScopeContainer : public AbstractContainer {
private:
    using InstancePointer = typename AbstractContainer::QObjectPointer;
    using InstacneFactory = std::function<InstancePointer()>;
    InstacneFactory m_factory;
public:
    ScopeContainer(InstacneFactory factory);
    virtual InstancePointer load() override;
    virtual bool contains() const override;
};
}

