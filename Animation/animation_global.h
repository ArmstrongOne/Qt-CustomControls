#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(ANIMATION_LIB)
#  define ANIMATION_EXPORT Q_DECL_EXPORT
# else
#  define ANIMATION_EXPORT Q_DECL_IMPORT
# endif
#else
# define ANIMATION_EXPORT
#endif
