#pragma once
#include "../AbstractContainer/AbstractContainer.h"
#include <functional>


namespace QtIoc {
/*!
 * \brief The ScopeContainer class
 * \details Базовый класс контейнера для объекта,
 * обеспечивающего scope-lifetime.
 *
 * Scope-lifetime:
 * новый объект для каждого вызова.
 *
 * \author Ilya Bykonya
 * \date 21.06.2022
 */
class QTIOCCONTAINER_EXPORT ScopeContainer : public AbstractContainer {
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

