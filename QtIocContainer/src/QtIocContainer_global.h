#pragma once

#include <QtCore/qglobal.h>

#if defined(QTIOCCONTAINER_LIBRARY)
#  define QTIOCCONTAINER_EXPORT Q_DECL_EXPORT
#else
#  define QTIOCCONTAINER_EXPORT Q_DECL_IMPORT
#endif
