#include <QCoreApplication>
#include <QtIocContainer>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QtIoc::IocContainer::instance()->store_dependency("timer", std::make_shared<QtIoc::SingletonContainer>(new QTimer));

    std::function func = [](QPointer<QTimer>) ->int { return 42; };
    qDebug() << "Call result: " << QtIoc::InstanceCaller{ QtIoc::IocContainer::instance() }.call(func, { "timer" });


    return qApp->exec();
}
