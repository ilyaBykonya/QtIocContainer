CONFIG(debug, debug|release) { LIB_SUFFIX = d }

QT -= gui
TEMPLATE = lib
CONFIG += c++11 build_all
DEFINES += QTIOCCONTAINER_LIBRARY

TARGET = QtIocContainer$${LIB_SUFFIX}
DLLDESTDIR = $${PWD}/lib
DESTDIR = $${PWD}/lib

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    src/Helpers/DependencyLoader.h \
    src/Helpers/InjectionMacroses.h \
    src/InstanceContainers/AbstractContainer/AbstractContainer.h \
    src/Exceptions/ElementNotStoredException/ElementNotStoredException.h \
    src/Exceptions/FailedIntanceCastOnLoadException/FailedIntanceCastOnLoadException.h \
    src/Exceptions/InvalidContainerException/InvalidContainerException.h \
    src/Helpers/DependencyInjector.h \
    src/InstanceContainers/ScopeContainer/ScopeContainer.h \
    src/InstanceContainers/SharedContainer/SharedContainer.h \
    src/InstanceContainers/SingletonContainer/SingletonContainer.h \
    src/IocContainer/IocContainer.h \
    src/QtDependencyInjection_global.h

SOURCES += \
    src/Exceptions/ElementNotStoredException/ElementNotStoredException.cpp \
    src/Exceptions/FailedIntanceCastOnLoadException/FailedIntanceCastOnLoadException.cpp \
    src/Exceptions/InvalidContainerException/InvalidContainerException.cpp \
    src/InstanceContainers/ScopeContainer/ScopeContainer.cpp \
    src/InstanceContainers/SharedContainer/SharedContainer.cpp \
    src/InstanceContainers/SingletonContainer/SingletonContainer.cpp \
    src/IocContainer/IocContainer.cpp

DISTFILES += \
    include/QtIocContainer

# Default rules for deployment.
unix {
    target.path = /usr/lib
    INSTALLS += target
}
