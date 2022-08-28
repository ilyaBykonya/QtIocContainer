#include <QCoreApplication>
#include <QtIocContainer>
#include "TestService/TestService.h"
#include <QMetaMethod>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QPointer<QtIoc::IocContainer> container = QtIoc::IocContainer::instance();
    container->store_dependency<QTimer>(QSharedPointer<QtIoc::SingletonContainer>::create(new QTimer));
    container->store_dependency<TestService>(QSharedPointer<QtIoc::ScopeContainer>::create([]{ return new TestService; }));

    QtIoc::DependencyLoader<TestService>{ container }.load()->start();
    QtIoc::DependencyLoader<QTimer>{ container }->start(500);

    return app.exec();
}
