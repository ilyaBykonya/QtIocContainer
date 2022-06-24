#pragma once

#include <QtCore/qglobal.h>

#if defined(QTIOCCONTAINER_LIBRARY)
#  define QTDEPENDENCYINJECTION_EXPORT Q_DECL_EXPORT
#else
#  define QTDEPENDENCYINJECTION_EXPORT Q_DECL_IMPORT
#endif
