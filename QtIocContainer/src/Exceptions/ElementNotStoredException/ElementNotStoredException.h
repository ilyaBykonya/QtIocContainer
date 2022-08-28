#pragma once
#include <QException>
#include <QString>


namespace QtIoc {
/*!
 * \brief The ElementNotStoredException exception
 * \details The container does not have a dependency with that name.
 */
template<typename Type>
class ElementNotStoredException : public QException {
public:
    virtual const char *what() const override {
        return "Element not stored in IoC";
    }
};
}
