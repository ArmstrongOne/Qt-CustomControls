#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(CUSTOMSLIDER_LIB)
#  define CUSTOMSLIDER_EXPORT Q_DECL_EXPORT
# else
#  define CUSTOMSLIDER_EXPORT Q_DECL_IMPORT
# endif
#else
# define CUSTOMSLIDER_EXPORT
#endif
