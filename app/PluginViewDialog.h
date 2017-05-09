/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    PluginViewDialog.h
 * @brief
 *******************************************************************************
 */
#ifndef PLUGINVIEWDIALOG_H
#define PLUGINVIEWDIALOG_H

#include <QDialog>

namespace Ui {
class PluginViewDialog;
}

class PluginViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PluginViewDialog(QWidget *parent = 0);
    ~PluginViewDialog();

private:
    Ui::PluginViewDialog *ui;
};

#endif // PLUGINVIEWDIALOG_H
