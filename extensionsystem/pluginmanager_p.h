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


#ifndef PLUGINMANAGER_P_H
#define PLUGINMANAGER_P_H

#include "pluginspec.h"

#include <QSet>
#include <QStringList>
#include <QObject>
#include <QScopedPointer>

QT_BEGIN_NAMESPACE
class QTime;
class QTimer;
class QSettings;
class QEventLoop;
QT_END_NAMESPACE

namespace ExtensionSystem {

class PluginManager;
class PluginCollection;

namespace Internal {

class PluginSpecPrivate;

class EXTENSIONSYSTEM_EXPORT PluginManagerPrivate : QObject
{
    Q_OBJECT
public:
    PluginManagerPrivate(PluginManager *pluginManager);
    virtual ~PluginManagerPrivate();

    // Object pool operations
    void addObject(QObject *obj);
    void removeObject(QObject *obj);

    // Plugin operations
    void loadPlugins();
    void shutdown();
    void setPluginPaths(const QStringList &paths);
    QList<PluginSpec *> loadQueue();
    void loadPlugin(PluginSpec *spec, PluginSpec::State destState);
    void resolveDependencies();
    void initProfiling();
    void profilingReport(const char *what, const PluginSpec *spec = 0);
    void setSettings(QSettings *settings);
    void setGlobalSettings(QSettings *settings);
    void readSettings();
    void writeSettings();
    void disablePluginIndirectly(PluginSpec *spec);

    QHash<QString, PluginCollection *> pluginCategories;
    QList<PluginSpec *> pluginSpecs;
    QStringList pluginPaths;
    QString extension;
    QList<QObject *> allObjects; // ### make this a QList<QPointer<QObject> > > ?
    QStringList defaultDisabledPlugins;
    QStringList disabledPlugins;
    QStringList forceEnabledPlugins;
    // delayed initialization
    QTimer *delayedInitializeTimer;
    QList<PluginSpec *> delayedInitializeQueue;
    // ansynchronous shutdown
    QList<PluginSpec *> asynchronousPlugins; // plugins that have requested async shutdown
    QEventLoop *shutdownEventLoop; // used for async shutdown

    QStringList arguments;
    QScopedPointer<QTime> m_profileTimer;
    int m_profileElapsedMS;
    unsigned m_profilingVerbosity;
    QSettings *settings;
    QSettings *globalSettings;

    // Look in argument descriptions of the specs for the option.
    PluginSpec *pluginForOption(const QString &option, bool *requiresArgument) const;
    PluginSpec *pluginByName(const QString &name) const;

    // used by tests
    static PluginSpec *createSpec();
    static PluginSpecPrivate *privateSpec(PluginSpec *spec);

private slots:
    void nextDelayedInitialize();
    void asyncShutdownFinished();

private:
    PluginCollection *defaultCollection;
    PluginManager *q;

    void readPluginPaths();
    bool loadQueue(PluginSpec *spec,
            QList<PluginSpec *> &queue,
            QList<PluginSpec *> &circularityCheckQueue);
    void stopAll();
    void deleteAll();
};

} // namespace Internal
} // namespace ExtensionSystem

#endif // PLUGINMANAGER_P_H
