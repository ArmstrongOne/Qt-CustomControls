#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CUSTOMWIN_LIB)
#  define CUSTOMWIN_EXPORT Q_DECL_EXPORT
# else
#  define CUSTOMWIN_EXPORT Q_DECL_IMPORT
# endif
#else
# define CUSTOMWIN_EXPORT
#endif
