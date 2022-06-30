#pragma once
#include <QPointer>
#include <QTimer>

class CreatableService : public QObject {
private:
    Q_OBJECT
public:
    CreatableService(QPointer<QTimer>);
public slots:
    void handleTimer();
};

