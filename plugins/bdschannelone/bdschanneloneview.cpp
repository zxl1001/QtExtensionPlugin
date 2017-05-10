/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    smmanagerview.cpp
 * @brief
 *******************************************************************************
 */
#include "bdschanneloneview.h"
#include "ui_bdschanneloneview.h"
#include "pluginprotocol/pluginprotocolextence.h"

namespace BDSChannelOne {
BDSChannelOneView::BDSChannelOneView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BDSChannelOneView)
{
    ui->setupUi(this);
}

BDSChannelOneView::~BDSChannelOneView()
{
    delete ui;
}

void BDSChannelOneView::on_pushButton_clicked()
{
    emit PluginProtoco::PluginProtocolExtence::instance()->signalPluginsName(this->property("MyName").toString());
}
//namespace end
}


