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


#ifndef EXTENSIONSYSTEM_PLUGINMANAGER_H
#define EXTENSIONSYSTEM_PLUGINMANAGER_H

#include "extensionsystem_global.h"
#include "aggregate.h"

#include <QObject>
#include <QReadWriteLock>
#include <QStringList>

QT_BEGIN_NAMESPACE
class QTextStream;
class QSettings;
QT_END_NAMESPACE

namespace ExtensionSystem {
class PluginCollection;

namespace Internal {
class PluginManagerPrivate;
}

class IPlugin;
class PluginSpec;

typedef QList<PluginSpec *> PluginSpecSet;

class EXTENSIONSYSTEM_EXPORT PluginManager : public QObject
{
    Q_OBJECT

public:
    static PluginManager *instance();

    PluginManager();
    virtual ~PluginManager();
    /*-------------------------------------------
    * Object pool operations
    ---------------------------------------------*/
    static void addObject(QObject *obj);
    static void removeObject(QObject *obj);
    static QList<QObject *> allObjects();

    template <typename T> static QList<T *> getObjects()
    {
        QReadLocker lock(&m_instance->m_lock);
        QList<T *> results;
        QList<QObject *> all = allObjects();
        QList<T *> result;
        foreach (QObject *obj, all)
        {
            result = ExtensionSystem::query_all<T>(obj);
            if (!result.isEmpty())
            {
                results += result;
            }
        }
        return results;
    }

    template <typename T> static T *getObject()
    {
        QReadLocker lock(&m_instance->m_lock);
        QList<QObject *> all = allObjects();
        T *result = 0;
        foreach (QObject *obj, all)
        {
            if ((result = ExtensionSystem::query<T>(obj)) != 0)
                break;
        }
        return result;
    }

    static QObject *getObjectByName(const QString &name);
    static QObject *getObjectByClassName(const QString &className);
    /*-------------------------------------------
    * Plugin operations
    ---------------------------------------------*/
    static QList<PluginSpec *> loadQueue();
    static void loadPlugins();
    static QStringList pluginPaths();
    static void setPluginPaths(const QStringList &paths);
    static QList<PluginSpec *> plugins();
    static QHash<QString, PluginCollection *> pluginCollections();
    static void setFileExtension(const QString &extension);
    static QString fileExtension();
    static bool hasError();
    /*-------------------------------------------
    * Settings
    ---------------------------------------------*/
    static void setSettings(QSettings *settings);
    static QSettings *settings();
    static void setGlobalSettings(QSettings *settings);
    static QSettings *globalSettings();
    static void writeSettings();
    /*-------------------------------------------
    * command line arguments
    ---------------------------------------------*/
    static QStringList arguments();
    static bool parseOptions(const QStringList &args,const QMap<QString, bool> &appOptions,
                             QMap<QString, QString> *foundAppOptions,QString *errorString);
    static void formatOptions(QTextStream &str, int optionIndentation, int descriptionIndentation);
    static void formatPluginOptions(QTextStream &str, int optionIndentation, int descriptionIndentation);
    static void formatPluginVersions(QTextStream &str);

    static QString serializedArguments();

    static void profilingReport(const char *what, const PluginSpec *spec = 0);

signals:
    void objectAdded(QObject *obj);
    void aboutToRemoveObject(QObject *obj);

    void pluginsChanged();
public slots:
    void shutdown();
private:
    Internal::PluginManagerPrivate *d;
    static PluginManager *m_instance;
    mutable QReadWriteLock m_lock;

    friend class Internal::PluginManagerPrivate;
};

} // namespace ExtensionSystem

#endif // EXTENSIONSYSTEM_PLUGINMANAGER_H
