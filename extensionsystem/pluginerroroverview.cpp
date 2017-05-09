#include "pluginerroroverview.h"
#include "ui_pluginerroroverview.h"


Q_DECLARE_METATYPE(ExtensionSystem::PluginSpec*)

namespace ExtensionSystem {
namespace Internal {

class PluginErrorOverviewPrivate : public QObject
{
    Q_OBJECT
public:
    PluginErrorOverviewPrivate(QDialog *dialog);
    ~PluginErrorOverviewPrivate();

private slots:
    void showDetails(QListWidgetItem *item);

private:
    Ui::PluginErrorOverview *m_ui;
};

} // Internal
} // ExtensionSystem

using namespace ExtensionSystem;
using namespace ExtensionSystem::Internal;

PluginErrorOverview::PluginErrorOverview(QWidget *parent) :
    QDialog(parent),d(new PluginErrorOverviewPrivate(this))
{
}

PluginErrorOverview::~PluginErrorOverview()
{
    delete d;
}

PluginErrorOverviewPrivate::PluginErrorOverviewPrivate(QDialog *dialog)
    : m_ui(new Ui::PluginErrorOverview)
{
    m_ui->setupUi(dialog);
    m_ui->buttonBox->addButton(tr("Continue"), QDialogButtonBox::AcceptRole);

    foreach (PluginSpec *spec, PluginManager::plugins())
    {
        /*---------------------------------------------------
        * only show errors on startup if plugin is enabled.
        -----------------------------------------------------*/
        if (spec->hasError() && spec->isEnabled() && !spec->isDisabledIndirectly())
        {
            QListWidgetItem *item = new QListWidgetItem(spec->name());
            item->setData(Qt::UserRole, qVariantFromValue(spec));
            m_ui->pluginList->addItem(item);
        }
    }

    connect(m_ui->pluginList, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this, SLOT(showDetails(QListWidgetItem*)));

    if (m_ui->pluginList->count() > 0)
    {
        m_ui->pluginList->setCurrentRow(0);
    }
}

PluginErrorOverviewPrivate::~PluginErrorOverviewPrivate()
{
    delete m_ui;
}

void PluginErrorOverviewPrivate::showDetails(QListWidgetItem *item)
{
    if (item)
    {
        PluginSpec *spec = item->data(Qt::UserRole).value<PluginSpec *>();
        m_ui->pluginError->setText(spec->errorString());
    } else
    {
        m_ui->pluginError->setText(QString());
    }
}

#include "pluginerroroverview.moc"
