/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    smmanagerview.h
 * @brief
 *******************************************************************************
 */
#ifndef BDSCHANNELONEVIEW_H
#define BDSCHANNELONEVIEW_H

#include <QDialog>

namespace Ui {
class BDSChannelOneView;
}

namespace BDSChannelOne {
class BDSChannelOneView : public QDialog
{
    Q_OBJECT

public:
    explicit BDSChannelOneView(QWidget *parent = 0);
    ~BDSChannelOneView();


private slots:
    void on_pushButton_clicked();

private:
    Ui::BDSChannelOneView *ui;
};
}
#endif // BDSCHANNELONEVIEW_H
