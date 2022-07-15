#include "FailedInstanceCastOnLoadException.h"

namespace QtIoc {
FailedInstanceCastOnLoadException::FailedInstanceCastOnLoadException(const QString&)
    :QException{}
    {
    }
const char* FailedInstanceCastOnLoadException::what() const {
    return "Cast dependency from QObject to some type was failed";
}
}
