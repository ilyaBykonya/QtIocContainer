#pragma once
#include <QtIocContainer>
#include <QTimer>

class TestService : public QObject
{
private:
    Q_OBJECT
public:
    Q_INJECT_IN_DEFAULT(QTimer, timer);
    void start();
    void handle();
};

