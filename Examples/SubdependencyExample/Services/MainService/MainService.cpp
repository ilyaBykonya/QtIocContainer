#include "MainService.h"
#include <QDebug>

MainService::MainService(QObject *parent)
    :AbstractService{ parent }
    {
    }

void MainService::execute() {
    qDebug() << "Main service worked";
    m_subservice->execute();
}

