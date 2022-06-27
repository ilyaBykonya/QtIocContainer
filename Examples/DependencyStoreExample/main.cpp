#include <QCoreApplication>
#include <QtIocContainer>
#include <QTimer>
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QPointer<QtIoc::IocContainer> container = QtIoc::IocContainer::instance();
    container->store_dependency("timer", std::make_shared<QtIoc::SingletonContainer>(new QTimer));

    QtIoc::DependencyLoader<QTimer> loader{ container, "timer" };
    QObject::connect(loader.load(), &QTimer::timeout, []{ qDebug() << "Timeout"; });
    loader->start(500);

    return app.exec();
}
