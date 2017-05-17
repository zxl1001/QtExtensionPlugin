/****************************************************************************
**
* @Project : Frameworks
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

#ifndef PLUGINDIALOG_H
#define PLUGINDIALOG_H

#include <QDialog>

class QPushButton;
class QLabel;

namespace ExtensionSystem {

class PluginSpec;
class PluginView;

}


class PluginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PluginDialog(QWidget *parent);

private slots:
    void updateRestartRequired();
    void updateButtons();
    void openDetails();
    void openDetails(ExtensionSystem::PluginSpec *spec);
    void openErrorDetails();
    void closeDialog();

private:
    ExtensionSystem::PluginView *m_view;

    QPushButton *m_detailsButton;
    QPushButton *m_errorDetailsButton;
    QPushButton *m_closeButton;
    QLabel *m_restartRequired;
    static bool m_isRestartRequired;
};


#endif // PLUGINDIALOG_H
