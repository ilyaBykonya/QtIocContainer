#include "Services/MainService/MainService.h"
#include "Services/SubService/SubService.h"
#include <QCoreApplication>
#include <QtIocContainer>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QPointer<QtIoc::IocContainer> container = QtIoc::IocContainer::instance();
    container->store_dependency("main_service", std::make_shared<QtIoc::SingletonContainer>(new MainService));
    container->store_dependency("subservice", std::make_shared<QtIoc::SingletonContainer>(new SubService));
    QtIoc::DependencyLoader<AbstractService>{ container, "main_service" }->execute();
    return app.exec();
}
