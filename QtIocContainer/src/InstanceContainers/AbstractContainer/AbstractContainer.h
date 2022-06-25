#pragma once
#include <QPointer>

namespace QtIoc {
/*!
 * \brief The AbstractContainer class
 * \details The base container class for the instance,
 * stored in IocContainer.
 */
class AbstractContainer {
protected:
    using QObjectPointer = QPointer<QObject>;
public:
    virtual ~AbstractContainer() = default;

    /*!
     * \brief load
     * \return QPointer<QObject>
     * \details Load object from container
     */
    virtual QObjectPointer load() = 0;
    /*!
     * \brief contains
     * \return bool
     * \details Checks if an instance exists in a container
     */
    virtual bool contains() const = 0;
};
}
