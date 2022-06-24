#pragma once
#include "../../QtDependencyInjection_global.h"
#include "../AbstractContainer/AbstractContainer.h"

namespace QtIoc {
/*!
 * \brief The StaticContainer class
 * \details Базовый класс контейнера для объекта,
 * обеспечивающего singleton-lifetime.
 *
 * Singleton-lifetime:
 * One object for each call.
 */
class QTDEPENDENCYINJECTION_EXPORT SingletonContainer : public AbstractContainer {
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
