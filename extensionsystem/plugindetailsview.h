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

#ifndef PLUGINDETAILSVIEW_H_
#define PLUGINDETAILSVIEW_H_

#include <QDir>
#include <QWidget>
#include "extensionsystem_global.h"
#include "pluginspec.h"

namespace ExtensionSystem {

class PluginSpec;

namespace Internal {
namespace Ui {
    class PluginDetailsView;
} // namespace Ui
} // namespace Internal


class EXTENSIONSYSTEM_EXPORT PluginDetailsView : public QWidget
{
    Q_OBJECT

public:
    PluginDetailsView(QWidget *parent = 0);
    ~PluginDetailsView();

    void update(PluginSpec *spec);

private:
    Internal::Ui::PluginDetailsView *ui;
};

} // namespace ExtensionSystem

#endif
