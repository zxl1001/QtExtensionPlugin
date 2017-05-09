
#ifndef BDSCHANNELONEPLUGIN_H
#define BDSCHANNELONEPLUGIN_H

#include <extensionsystem/iplugin.h>
#include <QtPlugin>
#include <QTextCodec>
#include <QGraphicsView>
#include <QMessageBox>

using namespace ExtensionSystem;

namespace BDSChannelOne {

class BDSChannelOnePlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.BlueBlazer.Frameworks.Plugin" FILE "bdschannelone.json")
    Q_INTERFACES(ExtensionSystem::IPlugin)
public:
    explicit BDSChannelOnePlugin();
public:
    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    IPlugin::ShutdownFlag aboutToShutdown();
};

}

#endif // BDSCHANNELONEPLUGIN_H
