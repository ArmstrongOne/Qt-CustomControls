#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(BTNCONTROLS_LIB)
#  define BTNCONTROLS_EXPORT Q_DECL_EXPORT
# else
#  define BTNCONTROLS_EXPORT Q_DECL_IMPORT
# endif
#else
# define BTNCONTROLS_EXPORT
#endif
