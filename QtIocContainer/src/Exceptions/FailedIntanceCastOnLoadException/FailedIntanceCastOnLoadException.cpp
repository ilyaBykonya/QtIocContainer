#include "FailedIntanceCastOnLoadException.h"

namespace QtIoc {
FailedIntanceCastOnLoadException::FailedIntanceCastOnLoadException(const QString& name)
    :QException{},
     m_description{ QString{ "Invalid cast: [%1]" }.arg(name) }
    {
    }
const char* FailedIntanceCastOnLoadException::what() const {
    return m_description.toStdString().c_str();
}
}
