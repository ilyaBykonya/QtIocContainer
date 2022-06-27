#pragma once
#include "../DependencyLoader/DependencyLoader.h"
#include <QMetaObject>
#include <type_traits>
#include <functional>
#include <stdexcept>
#include <memory>
#include <array>

namespace QtIoc {
class InstanceCaller {
private:
    QPointer<IocContainer> m_container;
public:
    InstanceCaller();
    InstanceCaller(QPointer<IocContainer> container);

    template<typename ResultType, typename...Args>
    ResultType call(std::function<ResultType(Args...)> callable, const std::array<QString, sizeof...(Args)>& dependenciesNames) {
        return callPrivate<ResultType, Args...>(callable, dependenciesNames, 0);
    }
private:
    template<typename ResultType, typename...Args>
    ResultType callPrivate(std::function<ResultType(Args...)> callable, const std::array<QString, sizeof...(Args)>& dependenciesNames, int currentIndex) {
        return callable(DependencyLoader<Args>{ m_container, dependenciesNames[currentIndex++] }.load()...);
    }
};
}



