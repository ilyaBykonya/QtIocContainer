#pragma once
#include <QObject>

class AbstractService: public QObject {
private:
    Q_OBJECT
public:
    explicit AbstractService(QObject* parent = nullptr);
    virtual void execute() = 0;
};

