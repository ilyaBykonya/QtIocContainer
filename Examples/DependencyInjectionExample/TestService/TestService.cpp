#include "TestService.h"
#include <QDebug>


TestService::TestService(QPointer<QTimer> timer)
    :m_timer{ timer }
    {
    }

void TestService::start() {
    QObject::connect(m_timer, &QTimer::timeout,
    [this]{
        this->handle();
    });
}
void TestService::handle() {
    qDebug() << "Timeout";
}
