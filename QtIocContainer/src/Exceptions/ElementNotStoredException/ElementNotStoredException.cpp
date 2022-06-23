#include "ElementNotStoredException.h"

namespace QtIoc {
ElementNotStoredException::ElementNotStoredException(const QString& name)
    :QException{},
     m_description{ QString{ "Element not stored in container: [%1]" }.arg(name) }
    {
    }
const char* ElementNotStoredException::what() const {
    return m_description.toStdString().c_str();
}
}
