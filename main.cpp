/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：main.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年03月17日08时
*   描    述：
*
================================================================*/

#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "mainwindos.h"

int main(int argc , char *argv[])
{
    QApplication a(argc , argv);
    MainWindow man;
    man.show();
    a.exec();
    return 0;
}
