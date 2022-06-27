#include "ElementNotStoredException.h"

namespace QtIoc {
ElementNotStoredException::ElementNotStoredException(const QString&)
    :QException{}
    {
    }
const char* ElementNotStoredException::what() const {
    return "Element not stored in container";
}
}
