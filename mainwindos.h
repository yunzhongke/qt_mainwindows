/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：mainwindos.h
*   创 建 者：yunzhongke
*   创建日期：2018年03月17日08时
*   描    述：
*
================================================================*/


#ifndef _MAINWINDOS_H
#define _MAINWINDOS_H

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QTableView>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);
        virtual ~MainWindow();

    private:
        void m_init();

    private:
        QMenu *file;
        QMenu *edit; 
        QMenu *setting;
        QMenu *help;

        QToolBar *creat_file;
        QToolBar *open_file;
        QToolBar *save_file;
        QToolBar *read_file;

        QSplitter *splitter;
        QTreeWidget *tree;
        QTableView *table; 
};

#endif //MAINWINDOS_H
