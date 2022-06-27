#include <QCoreApplication>
#include <QtIocContainer>
#include "TestService/TestService.h"
#include <QMetaMethod>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QPointer<QtIoc::IocContainer> container{ new QtIoc::IocContainer() };
    container->store_dependency("timer", std::make_shared<QtIoc::SingletonContainer>(new QTimer));
    container->store_dependency("service", std::make_shared<QtIoc::ScopeContainer>([]{ return new TestService; }));

    QObject* service = new TestService;
    auto meta_info = service->metaObject();
    for(int i = 0; i < meta_info->methodCount(); ++i) {
        auto meta_method = meta_info->method(i);
        qDebug() << meta_method.name();
    }


    QtIoc::DependencyLoader<TestService>{ container, "service" }.load()->start();
    QtIoc::DependencyLoader<QTimer>{ container, "timer" }->start(500);

    return app.exec();
}
