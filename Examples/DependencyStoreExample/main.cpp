#include <QCoreApplication>
#include <QtIocContainer>
#include <QTimer>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    auto container = QtIoc::IocContainer::instance();
    container->store_dependency<QTimer>(QSharedPointer<QtIoc::SingletonContainer>::create(new QTimer));

    QtIoc::DependencyLoader<QTimer> loader{ container };
    QObject::connect(loader.load(), &QTimer::timeout, []{ qDebug() << "Timeout"; });
    loader->start(500);

    return app.exec();
}
