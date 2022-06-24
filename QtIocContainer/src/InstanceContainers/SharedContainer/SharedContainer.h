#pragma once
#include "../../QtIocContainer_global.h"
#include "../AbstractContainer/AbstractContainer.h"
#include <functional>


namespace QtIoc {
/*!
 * \brief The SharedContainer class
 * \details The base container class for the object,
 * providing shared-lifetime.
 *
 * Shared-lifetime:
 * The object lives as long as it is used by someone from the outside.
 * When all strong references to it are removed, it will be destroyed.
 * When requested again, the destroyed object will be re-created via a factory call.
 */
class QTIOCCONTAINER_EXPORT SharedContainer : public AbstractContainer {
private:
    using InstancePointer = typename AbstractContainer::QObjectPointer;
    using InstacneFactory = std::function<InstancePointer()>;
    InstacneFactory m_factory;
    InstancePointer m_instance;
public:
    SharedContainer(InstacneFactory factory);
    virtual ~SharedContainer() override;
public:
    virtual InstancePointer load() override;
    virtual bool contains() const override;
};
}
