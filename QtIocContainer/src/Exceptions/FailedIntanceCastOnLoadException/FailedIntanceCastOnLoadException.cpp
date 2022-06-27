#include "FailedIntanceCastOnLoadException.h"

namespace QtIoc {
FailedIntanceCastOnLoadException::FailedIntanceCastOnLoadException(const QString&)
    :QException{}
    {
    }
const char* FailedIntanceCastOnLoadException::what() const {
    return "Cast dependency from QObject to some type was failed";
}
}
