#include "CreatableService.h"
#include <QDebug>

CreatableService::CreatableService(QPointer<QTimer> timer) {
    if(timer) {
        connect(timer, &QTimer::timeout, this, &CreatableService::handleTimer);
        qDebug() << "Timer connected";
    } else {
        qWarning() << "Timer is null";
    }
}

void CreatableService::handleTimer() {
    qDebug() << "Timeout";
}
