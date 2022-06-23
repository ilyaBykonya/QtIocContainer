#pragma once
#include "../../QtIocContainer_global.h"
#include "../AbstractContainer/AbstractContainer.h"
#include <functional>


namespace QtIoc {
/*!
 * \brief The SharedContainer class
 * \details Базовый класс контейнера для объекта,
 * обеспечивающего shared-lifetime.
 *
 * Shared-lifetime:
 * объект живёт, пока ис пользуется кто-то извне.
 * когда все сильные ссылки на него удалены, он уничтожится.
 * при повторном запросе уничтоженный объект будет вновь создан через вызов фабрики.
 *
 * \author Ilya Bykonya
 * \date 21.06.2022
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
