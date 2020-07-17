#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(COMMONCHARTS_LIB)
#  define COMMONCHARTS_EXPORT Q_DECL_EXPORT
# else
#  define COMMONCHARTS_EXPORT Q_DECL_IMPORT
# endif
#else
# define COMMONCHARTS_EXPORT
#endif
