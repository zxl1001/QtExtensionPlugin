/****************************************************************************
**
* @Project : Frameworks
* @File: aggregate.h
* @Description:
* @Copyright: Copyright (c) 2014
* @Company:
* @WebSite: http://www.zchx.com/
* @author:
* @Revision History
* <pre>
* ----------------------------------------------------------------------
*   Ver     Date       Who        Comments
* ----- ----------  --------  ------------------------------------------
*   1.0  2013/08/12    yeguoxiong      FOR QT 5.1.0
* ----------------------------------------------------------------------
**
****************************************************************************/

#ifndef EXTENSIONSYSTEM_GLOBAL_H
#define EXTENSIONSYSTEM_GLOBAL_H

#include <qglobal.h>

#if defined(EXTENSIONSYSTEM_LIBRARY)
#  define EXTENSIONSYSTEM_EXPORT Q_DECL_EXPORT
#else
#  define EXTENSIONSYSTEM_EXPORT Q_DECL_IMPORT
#endif

#endif // EXTENSIONSYSTEM_GLOBAL_H
