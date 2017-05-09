
#ifndef SMMANAGERPLUGIN_H
#define SMMANAGERPLUGIN_H

#include <extensionsystem/iplugin.h>
#include <QtPlugin>
#include <QTextCodec>
#include <QGraphicsView>
#include <QMessageBox>

using namespace ExtensionSystem;

namespace SMManager {

class SMManagerPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.BlueBlazer.Frameworks.Plugin" FILE "smmanager.json")
    Q_INTERFACES(ExtensionSystem::IPlugin)
public:
    explicit SMManagerPlugin();
public:
    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    IPlugin::ShutdownFlag aboutToShutdown();
};

}

#endif // SMMANAGERPLUGIN_H
