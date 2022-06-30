#include <QCoreApplication>
#include <QtIocContainer>
#include "CreatableService/CreatableService.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QtIoc::IocContainer::instance()->store_dependency("timer", std::make_shared<QtIoc::SingletonContainer>(new QTimer));

    auto service = QtIoc::InstanceCreator{}.create<CreatableService, QPointer<QTimer>>({ "timer" });
    QtIoc::DependencyLoader<QTimer>{ "timer" }->start(500);

    return app.exec();
}
