/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    PluginViewDialog.cpp
 * @brief
 *******************************************************************************
 */
#include "PluginViewDialog.h"
#include "ui_PluginViewDialog.h"
#include "extensionsystem/pluginview.h"

#include <QVBoxLayout>

PluginViewDialog::PluginViewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PluginViewDialog)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(new ExtensionSystem::PluginView(this));
    setLayout(layout);
}

PluginViewDialog::~PluginViewDialog()
{
    delete ui;
}
