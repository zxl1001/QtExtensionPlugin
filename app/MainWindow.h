/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    MainWindow.h
 * @brief
 *******************************************************************************
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "extensionsystem/pluginmanager.h"
#include "extensionsystem/pluginspec.h"
#include "extensionsystem/pluginerroroverview.h"
#include "extensionsystem/plugindetailsview.h"
#include <QMainWindow>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

Q_SIGNALS:
    void aboutToQuit();
public slots:
    void pluginObjectAdded(QObject *obj);

private slots:
    void on_pluginsDetailListViewBtn_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QSettings *m_setting;
    ExtensionSystem::PluginManager plgManager;
    ExtensionSystem::PluginDetailsView *m_view;
};

#endif // MAINWINDOW_H
