#include "bdschanneloneplugin.h"
#include "bdschanneloneview.h"
#include <QTranslator>
#include <QLocale>
#include <QCoreApplication>
#include <QDebug>

namespace BDSChannelOne {

BDSChannelOnePlugin::BDSChannelOnePlugin() :
    ExtensionSystem::IPlugin()
{
}

bool BDSChannelOnePlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)
    qDebug()<<__FILE__<<__LINE__<<"BDSChannelOnePlugin::initialize";
    QTranslator *translator = new QTranslator(this);
    translator->load(QLocale::system(), "bdschannelone", ".", ":/translations");
    qApp->installTranslator(translator);
    return true;
}

void BDSChannelOnePlugin::extensionsInitialized()
{
    qDebug()<<__FILE__<<__LINE__<<"BDSChannelOnePlugin::extensionsInitialized";
    BDSChannelOneView *widget = new BDSChannelOneView;
    widget->setProperty("MyName", "BDSChannelOnePluginView");
    addAutoReleasedObject(widget);
}

IPlugin::ShutdownFlag BDSChannelOnePlugin::aboutToShutdown()
{
    return IPlugin::SynchronousShutdown;
}
}
/*-------------------------------------------
*  need to this code
---------------------------------------------*/
Q_EXPORT_PLUGIN(BDSChannelOnePlugin)

