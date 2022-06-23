#include "SubService.h"
#include <QDebug>

SubService::SubService(QObject *parent)
    :AbstractService{ parent }
    {
    }

void SubService::execute() {
    qDebug() << "Child service worked";
}
