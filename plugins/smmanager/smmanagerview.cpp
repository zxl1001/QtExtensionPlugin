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
#include "smmanagerview.h"
#include "ui_smmanagerview.h"

namespace SMManager {
SMManagerView::SMManagerView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SMManagerView)
{
    ui->setupUi(this);
}

SMManagerView::~SMManagerView()
{
    delete ui;
}
//name space end
}
