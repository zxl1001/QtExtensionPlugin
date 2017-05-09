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
#ifndef SMMANAGERVIEW_H
#define SMMANAGERVIEW_H

#include <QDialog>

namespace Ui {
class SMManagerView;
}

namespace SMManager {
class SMManagerView : public QDialog
{
    Q_OBJECT

public:
    explicit SMManagerView(QWidget *parent = 0);
    ~SMManagerView();

private:
    Ui::SMManagerView *ui;
};
}
#endif // SMMANAGERVIEW_H
