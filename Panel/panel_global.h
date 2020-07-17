#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(PANEL_LIB)
#  define PANEL_EXPORT Q_DECL_EXPORT
# else
#  define PANEL_EXPORT Q_DECL_IMPORT
# endif
#else
# define PANEL_EXPORT
#endif
