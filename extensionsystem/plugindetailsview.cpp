#include "plugindetailsview.h"
#include "ui_plugindetailsview.h"

/*!
    \class ExtensionSystem::PluginDetailsView
    \brief Widget that displays the contents of a PluginSpec.

    Can be used for integration in the application that
    uses the plugin manager.

    \sa ExtensionSystem::PluginView
*/

using namespace ExtensionSystem;
/*---------------------------------------------------
*
*    \fn PluginDetailsView::PluginDetailsView(QWidget *parent)
*    Constructs a new view with given \a parent widget.
*
-----------------------------------------------------*/
PluginDetailsView::PluginDetailsView(QWidget *parent)
    : QWidget(parent),ui(new Internal::Ui::PluginDetailsView())
{
    ui->setupUi(this);
}
/*---------------------------------------------------
*
*    \fn PluginDetailsView::~PluginDetailsView()
*    \internal
*
-----------------------------------------------------*/
PluginDetailsView::~PluginDetailsView()
{
    delete ui;
}
/*---------------------------------------------------
*
*    \fn void PluginDetailsView::update(PluginSpec *spec)
*    Reads the given \a spec and displays its values
*    in this PluginDetailsView.
*
-----------------------------------------------------*/
void PluginDetailsView::update(PluginSpec *spec)
{
    ui->name->setText(spec->name());
    ui->version->setText(spec->version());
    ui->compatVersion->setText(spec->compatVersion());
    ui->vendor->setText(spec->vendor());
    const QString link = QString::fromLatin1("<a href=\"%1\">%1</a>").arg(spec->url());
    ui->url->setText(link);
    QString component = tr("None");
    if (!spec->category().isEmpty())
    {
        component = spec->category();
    }
    ui->component->setText(component);
    ui->location->setText(QDir::toNativeSeparators(spec->filePath()));
    ui->description->setText(spec->description());
    ui->copyright->setText(spec->copyright());
    ui->license->setText(spec->license());
    QStringList depStrings;
    foreach (const PluginDependency &dep, spec->dependencies())
    {
        QString depString = dep.name;
        depString += QLatin1String(" (");
        depString += dep.version;
        if (dep.type == PluginDependency::Optional)
        {
            depString += QLatin1String(", optional");
        }
        depString += QLatin1Char(')');
        depStrings.append(depString);
    }
    ui->dependencies->addItems(depStrings);
}
