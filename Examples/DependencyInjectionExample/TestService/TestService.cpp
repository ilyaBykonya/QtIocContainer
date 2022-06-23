#include "TestService.h"
#include <QDebug>


void TestService::start() {
    QObject::connect(m_timer, &QTimer::timeout,
    [this]{
        this->handle();
    });
}
void TestService::handle() {
    qDebug() << "Timeout";
}
