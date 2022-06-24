#pragma once
#include "../AbstractService/AbstractService.h"
#include <QtIocContainer>

class MainService : public AbstractService {
private:
    Q_OBJECT
public:
    Q_INJECT_IN_DEFAULT(AbstractService, subservice);
    explicit MainService(QObject *parent = nullptr);
    virtual void execute() override;
};


