#pragma once
#include <QAbstractEventDispatcher>
#include <QtIocContainer>
#include <QTimer>

class TestService : public QObject
{
private:
    Q_OBJECT
public:
    TestService() = default;
    TestService(QPointer<QTimer> timer);
    Q_INJECT_IN_DEFAULT(QTimer, timer);
    void start();
    void handle();
};

