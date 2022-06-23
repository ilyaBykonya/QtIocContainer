#pragma once
#include "../AbstractService/AbstractService.h"

class SubService : public AbstractService {
private:
    Q_OBJECT
public:
    explicit SubService(QObject *parent = nullptr);
    virtual void execute() override;
};

