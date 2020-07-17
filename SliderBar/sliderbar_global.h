#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SLIDERBAR_LIB)
#  define SLIDERBAR_EXPORT Q_DECL_EXPORT
# else
#  define SLIDERBAR_EXPORT Q_DECL_IMPORT
# endif
#else
# define SLIDERBAR_EXPORT
#endif
