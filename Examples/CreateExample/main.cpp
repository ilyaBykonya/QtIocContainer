#include <QCoreApplication>
#include <QtIocContainer>
#include "CreatableService/CreatableService.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QtIoc::IocContainer::instance()->store_dependency<QTimer>({}, QSharedPointer<QtIoc::SingletonContainer>::create(new QTimer));

    auto service = QtIoc::InstanceCreator{}.create<CreatableService, QPointer<QTimer>>();
    QtIoc::DependencyLoader<QTimer>{}->start(500);

    return app.exec();
}
