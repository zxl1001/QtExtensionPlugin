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


#ifndef PLUGINERROROVERVIEW_H
#define PLUGINERROROVERVIEW_H

#include "extensionsystem_global.h"
#include "pluginspec.h"
#include "pluginmanager.h"
#include <QDialog>

namespace ExtensionSystem {

class PluginManager;

namespace Internal {
class PluginErrorOverviewPrivate;
}

class EXTENSIONSYSTEM_EXPORT PluginErrorOverview : public QDialog
{
    Q_OBJECT

public:
    explicit PluginErrorOverview(QWidget *parent = 0);
    ~PluginErrorOverview();

private:
    Internal::PluginErrorOverviewPrivate *d;
};

} // ExtensionSystem

#endif // PLUGINERROROVERVIEW_H
