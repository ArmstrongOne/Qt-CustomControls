#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PROGRESSBAR_LIB)
#  define PROGRESSBAR_EXPORT Q_DECL_EXPORT
# else
#  define PROGRESSBAR_EXPORT Q_DECL_IMPORT
# endif
#else
# define PROGRESSBAR_EXPORT
#endif
