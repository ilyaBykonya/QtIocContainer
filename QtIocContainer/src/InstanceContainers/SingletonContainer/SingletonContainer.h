#pragma once
#include "../../QtIocContainer_global.h"
#include "../AbstractContainer/AbstractContainer.h"

namespace QtIoc {
/*!
 * \brief The StaticContainer class
 * \details Базовый класс контейнера для объекта,
 * обеспечивающего singleton-lifetime.
 *
 * Singleton-lifetime:
 * общий объект для каждого вызова.
 *
 * \author Ilya Bykonya
 * \date 21.06.2022
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
