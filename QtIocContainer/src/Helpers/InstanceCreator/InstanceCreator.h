#pragma once
#include "../DependencyLoader/DependencyLoader.h"
#include <QMetaObject>
#include <type_traits>
#include <stdexcept>
#include <memory>
#include <array>

namespace QtIoc {
class InstanceCreator {
private:
    QPointer<IocContainer> m_container;
public:
    InstanceCreator();
    InstanceCreator(QPointer<IocContainer> container);

    template<typename ResultType, typename...Args>
    QPointer<ResultType> create() {
        return QPointer<ResultType>{ new ResultType{ DependencyLoader<Args>{ m_container }.load()... } };
    }
};
}
