#pragma once

#include <QtGlobal>

#if defined(CODEINSIGHT_LIBRARY)
#  define CODEINSIGHTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CODEINSIGHTSHARED_EXPORT Q_DECL_IMPORT
#endif
