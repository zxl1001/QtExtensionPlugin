/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    main.cpp
 * @brief
 *******************************************************************************
 */
#include "MainWindow.h"
#include <QCoreApplication>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QObject::connect(&a, SIGNAL(aboutToQuit()), &w, SIGNAL(aboutToQuit()));
    return a.exec();
}
