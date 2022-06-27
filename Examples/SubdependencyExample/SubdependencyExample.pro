QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include($${PWD}/../../QtIocContainer/QtIocContainer.pri)

HEADERS += \
    Services/AbstractService/AbstractService.h \
    Services/MainService/MainService.h \
    Services/SubService/SubService.h

SOURCES += \
    Services/AbstractService/AbstractService.cpp \
    Services/MainService/MainService.cpp \
    Services/SubService/SubService.cpp \
    main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
