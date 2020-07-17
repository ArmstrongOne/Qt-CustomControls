#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(DASHBOARD_LIB)
#  define DASHBOARD_EXPORT Q_DECL_EXPORT
# else
#  define DASHBOARD_EXPORT Q_DECL_IMPORT
# endif
#else
# define DASHBOARD_EXPORT
#endif
