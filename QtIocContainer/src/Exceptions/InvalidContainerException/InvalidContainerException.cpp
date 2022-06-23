#include "InvalidContainerException.h"


namespace QtIoc {
InvalidContainerException::InvalidContainerException(const QString& name)
    :QException{},
     m_description{ QString{ "Invalid internal container: [%1]" }.arg(name) }
    {
    }
const char* InvalidContainerException::what() const {
    return m_description.toStdString().c_str();
}
}



