#pragma once
#include "../../QtIocContainer_global.h"
#include <QPointer>

namespace QtIoc {
/**
 * \brief The AbstractContainer class
 * \details Базовый класс контейнера для объекта,
 * сохраняемый в IocContainer-е.
 *
 * \author Ilya Bykonya
 * \date 21.06.2022
 */
class QTIOCCONTAINER_EXPORT AbstractContainer {
protected:
    using QObjectPointer = QPointer<QObject>;
public:
    virtual ~AbstractContainer() = default;
    virtual QObjectPointer load() = 0;
    virtual bool contains() const = 0;
};
}
