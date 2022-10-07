#include <QCoreApplication>
#include <QtIocContainer>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QtIoc::IocContainer::instance()->store_dependency<QTimer>({}, QSharedPointer<QtIoc::SingletonContainer>::create(new QTimer));

    std::function func = [](QPointer<QTimer>) ->int { return 42; };
    qDebug() << "Call result: " << QtIoc::InstanceCaller{}.call(func);


    return qApp->exec();
}
