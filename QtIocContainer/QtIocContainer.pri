CONFIG += c++11

HEADERS += \
    $$PWD/src/Helpers/InstanceCaller/InstanceCaller.h \
    $${PWD}/src/Helpers/InstanceCreator/InstanceCreator.h \
    $${PWD}/src/Helpers/DependencyInjector/DependencyInjector.h \
    $${PWD}/src/Helpers/DependencyLoader/DependencyLoader.h \
    $${PWD}/src/Helpers/InjectionMacroses.h \
    $${PWD}/src/Exceptions/ElementNotStoredException/ElementNotStoredException.h \
    $${PWD}/src/Exceptions/FailedIntanceCastOnLoadException/FailedIntanceCastOnLoadException.h \
    $${PWD}/src/Exceptions/InvalidContainerException/InvalidContainerException.h \
    $${PWD}/src/InstanceContainers/AbstractContainer/AbstractContainer.h \
    $${PWD}/src/InstanceContainers/ScopeContainer/ScopeContainer.h \
    $${PWD}/src/InstanceContainers/SharedContainer/SharedContainer.h \
    $${PWD}/src/InstanceContainers/SingletonContainer/SingletonContainer.h \
    $${PWD}/src/IocContainer/IocContainer.h

SOURCES += \
    $$PWD/src/Helpers/InstanceCaller/InstanceCaller.cpp \
    $${PWD}/src/Helpers/InstanceCreator/InstanceCreator.cpp \
    $${PWD}/src/Helpers/DependencyInjector/DependencyInjector.cpp \
    $${PWD}/src/Exceptions/ElementNotStoredException/ElementNotStoredException.cpp \
    $${PWD}/src/Exceptions/FailedIntanceCastOnLoadException/FailedIntanceCastOnLoadException.cpp \
    $${PWD}/src/Exceptions/InvalidContainerException/InvalidContainerException.cpp \
    $${PWD}/src/InstanceContainers/ScopeContainer/ScopeContainer.cpp \
    $${PWD}/src/InstanceContainers/SharedContainer/SharedContainer.cpp \
    $${PWD}/src/InstanceContainers/SingletonContainer/SingletonContainer.cpp \
    $${PWD}/src/IocContainer/IocContainer.cpp

OTHER_FILES += \
    $${PWD}/include/QtIocContainer

INCLUDEPATH += \
    $${PWD}/include \
    $${PWD}/src

DEPENDPATH += \
    $${PWD}/include \
    $${PWD}/src
