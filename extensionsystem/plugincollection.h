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

#ifndef PLUGINCOLLECTION_H
#define PLUGINCOLLECTION_H

#include "extensionsystem_global.h"

#include <QList>
#include <QString>

namespace ExtensionSystem {
class PluginSpec;

class EXTENSIONSYSTEM_EXPORT PluginCollection
{
    
public:
    explicit PluginCollection(const QString& name);
    ~PluginCollection();
    
    QString name() const;
    void addPlugin(PluginSpec *spec);
    void removePlugin(PluginSpec *spec);
    QList<PluginSpec *> plugins() const;
private:
    QString m_name;
    QList<PluginSpec *> m_plugins;
};

} // namespace ExtensionSystem

#endif // PLUGINCOLLECTION_H
