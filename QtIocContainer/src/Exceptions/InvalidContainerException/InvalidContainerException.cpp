#include "InvalidContainerException.h"


namespace QtIoc {
InvalidContainerException::InvalidContainerException(const QString&)
    :QException{}
    {
    }
const char* InvalidContainerException::what() const {
    return "Abstract dependency instance container return nullptr";
}
}



