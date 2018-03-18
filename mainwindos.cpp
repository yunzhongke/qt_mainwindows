/*================================================================
*   Copyright (C) 2018 Vertiv Tech Co Ltd. All rights reserved.
*   
*   文件名称：mainwindos.cpp
*   创 建 者：yunzhongke
*   创建日期：2018年03月17日10时
*   描    述：
*
================================================================*/

#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QStatusBar>
#include <QtGui/QStandardItemModel>
#include <QtGui/QStandardItem>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QHeaderView>
#include "mainwindos.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    m_init();
}

void MainWindow::m_init()
{
    setWindowTitle("MainWindow");
    //see https://www.cnblogs.com/lgxZJ/p/8097742.html
    //  菜单栏的样式
    setStyleSheet(
            "QMenu {"
                "background-color:white;"
                "border:1px solid rgb(0, 171, 255);"
                "padding:1px;"
                "}"
            "QMenu::indicator {"
                "width: 13px;"
                "height: 13px;"
                "}"
            "QMenu::item {"
                "color:red;"// 这里color是修改字体的颜色
                "background-color:transparent;"
                "padding:10px 1px;"/*设置菜单项文字上下和左右的内边距，效果就是菜单中的条目左右上下有了间隔,如果要加图标时将左右间隔加大*/
                "border-bottom:1px solid #DBDBDB;" //[>为菜单项之间添加横线间隔，起到分隔符的作用<]
                // addSeparator() 加分隔线
            "}"
            "QMenu::item:selected {"
                "color:green;"
                "background-color:transparent;"
            "}"
            "QMenuBar {"
                "width:60px;"
                "background-color:transparent;"
                "border:1px dotted gray;"
            "}"
            "QMenuBar::item {"
                "height:15px;"
                "width:60px;" 
                "color:red;" // 这里color是修改字体的颜色
                "background-color:transparent;"
                "border:2px groove gray;"
                "margin-right:60px;" // 菜单项之间的间隔
                "}"
            "QMenuBar::item:selected {"
                "color:green;"
                "background-color:transparent;"
                "}"
            /*"QMenuBar::item:pressed {"
                "color:black;"
                "background-color:transparent;"
                "};"*/
            "QToolButton {" /* 工具栏按钮*/
                "color:red;"
                "border: 2px solid #8f8f91;"
                "border-radius: 6px;"
                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);"
            "}"
            "QToolButton:pressed {"
                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);"
             "}"
             "QToolTip {" /* 工具栏按钮鼠标移动到时显示的信息*/
                "border: 1px solid darkkhaki;"
                "padding: 5px;"
                "border-radius: 3px;"
                "color:red;"
                "opacity: 200;" // 不透明
                "}"
            //see http://blog.csdn.net/fengyutongtt/article/details/52460716
            "QTreeWidget{"
                "background-color: white;"
                "font-size:17px;"  /* set the font properties*/  
                "color: red;"
            "}"
            "QTreeWidget::item{"
                "margin:10px;" //各个item之间的间隔
                //"background: #5B677A;"
                //"background-clip: margin;"
            "}"
            //http://blog.csdn.net/lwwl12/article/details/74932565
            "QTableView {"
                "color: red;"                                       /*表格内文字颜色*/
                "gridline-color: black;"                              /*表格内框颜色*/
                "background-color: white;"               /*表格内背景色*/
                "alternate-background-color: rgb(64, 64, 64);"
                "selection-color: white;"                             /*选中区域的文字颜色*/
                "selection-background-color: rgb(77, 77, 77);"        /*选中区域的背景色*/
                "border: 2px groove gray;"
                "border-radius: 0px;"
                "padding: 2px 4px;"
            "}"
            //表头样式 
            "QHeaderView {"
                "color: red;"
                "font: bold 10pt;"
                "background-color: rgb(108, 108, 108);"/*设置表头空白区域背景色*/
                "border: 0px solid rgb(144, 144, 144);"
                "border:0px solid rgb(191,191,191);"
                "border-left-color: rgba(255, 255, 255, 0);"
                "border-top-color: rgba(255, 255, 255, 0);"
                "border-radius:0px;"
                "min-height:29px;"
            "}"
            "QComboBox {"
                "border: 1px solid gray;"
                "border-radius: 3px;"
                "padding: 1px 18px 1px 30px;"//通过修改padding最后一个参数，来下拉框中文字的位置
                "min-width: 6em;"
                "color:red;"
                //"background:black;"
            "}"
            "QComboBox:!editable , QComboBox::drop-down:editable {"
                "background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                 "stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,"
                                 "stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);"
                //"background-color:black;"
            "}"
            "QComboBox QAbstractItemView{"
                "background-color:white;"
            "}"
            );
    // 设置窗体最大化
    setWindowState(Qt::WindowMaximized);

    QAction *creat_action = new QAction(QIcon("../Images/pic/baidu.png") , tr("创建文件") , this);
    // 设置该动作的快捷键，这里是内置。当然可以手动设置tr"ctrl+t"
    creat_action->setShortcut(QKeySequence::Open);
    QAction *open_action = new QAction(QIcon("../Images/pic/sina.png") , tr("&打开文件") , this);
    open_action->setShortcut(QString("ctrl+k"));
    file = menuBar()->addMenu(tr("&文件"));
    file->addAction(creat_action);
    file->addAction(open_action);

    edit = menuBar()->addMenu(tr("&编辑"));

    setting = menuBar()->addMenu(tr("&设置"));

    help = menuBar()->addMenu(tr("&帮助"));

    // 工具栏设置
    // see https://zhuanlan.zhihu.com/p/31176694
    creat_file = addToolBar(tr("&创建文件"));
    creat_file->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    creat_file->addAction(creat_action);

    open_file = addToolBar(tr("打开文件"));
    open_file->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    open_file->addAction(open_action);

    QToolBar *n_toolbar = addToolBar(tr("&选择类型"));
    // 下拉框
    // see http://blog.csdn.net/xgbing/article/details/7767530
    QComboBox *combox = new QComboBox(this);
    combox->addItem(QString("niaho"));
    combox->addItem(QString("women"));
    combox->addItem(QString("dajia"));
    n_toolbar->addWidget(combox);

    /*
     * @name 窗体布局
     * @{ */ 
        QHBoxLayout *h_layout = new QHBoxLayout();
        QVBoxLayout *v_layout = new QVBoxLayout();
        QWidget *widget = new QWidget(this);
        
        splitter = new QSplitter(Qt::Horizontal , this);
        splitter->setOpaqueResize(true);//拖拽时实时更新
        tree = new QTreeWidget(splitter);
        tree->setColumnCount(1);//设置列数
        tree->setHeaderLabel(tr("树"));//设置头的标题
        QTreeWidgetItem *tree_item1 = new QTreeWidgetItem(tree , QStringList(tr("孩子1")));//节点
        QTreeWidgetItem *tree_item1_1 = new QTreeWidgetItem(tree_item1 , QStringList(tr("孩子1下属1")));
        tree_item1->addChild(tree_item1_1);//添加子节点
        QTreeWidgetItem *tree_item2 = new QTreeWidgetItem(tree , QStringList(tr("孩子2")));
        QTreeWidgetItem *tree_item2_1 = new QTreeWidgetItem(tree_item2 , QStringList(tr("孩子1下属1")));
        QTreeWidgetItem *tree_item2_2 = new QTreeWidgetItem(tree_item2 , QStringList(tr("孩子1下属1")));
        tree_item2->addChild(tree_item2_1);
        tree_item2->addChild(tree_item2_2);
        tree->expandAll(); //所有结点全部展开
        //双击树结点的事件
        //see http://www.cnblogs.com/Romi/archive/2012/04/16/2452709.html
        
        table = new QTableView(splitter);
        //创建数据模型
        QStandardItemModel *model1 = new QStandardItemModel(widget);
        model1->setColumnCount(5);
        model1->setRowCount(7);
        model1->setHorizontalHeaderItem(0 , new QStandardItem(tr("Name")));
        model1->setHorizontalHeaderItem(1 , new QStandardItem(tr("No")));
        model1->setHorizontalHeaderItem(2 , new QStandardItem(tr("Sex")));
        model1->setHorizontalHeaderItem(3 , new QStandardItem(tr("Age")));
        model1->setHorizontalHeaderItem(4 , new QStandardItem(tr("College")));
        //往数据模型中添加数据
        QStandardItem *item_1 = new QStandardItem("hello");
        model1->setItem(3 , 0 , item_1);
        //设置数据模型数据居中显示
        model1->item(3 , 0)->setTextAlignment(Qt::AlignCenter);
        //see https://zhidao.baidu.com/question/2077514702593753228.html
        // 设置列宽自动适应窗口
        table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        // 设置行高自动适应窗口
        table->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        //将模型与tableview绑定
        table->setModel(model1);


        // Qsplitter 分割器分割窗口比例设定，tree与table的比例是2:6
        splitter->setStretchFactor(0 , 2);
        splitter->setStretchFactor(1 , 7);
        h_layout->addWidget(splitter);
   
        QStatusBar *status = new QStatusBar();
        // 设置临时信息
        status->showMessage(tr("欢迎光临！") , 2000);
        QLabel *permanent=new QLabel(widget);
        permanent->setFrameStyle(QFrame::Box|QFrame::Sunken);
        permanent->setText(tr("<a href=\"http://tengweitw.ueuo.com\">永久信息</a>"));
        permanent->setOpenExternalLinks(true);//设置可以打开网站链接
        status->addPermanentWidget(permanent);//显示永久信息

        v_layout->addLayout(h_layout);
        v_layout->addWidget(status);

        // 布局管理，各组件所占的比例:h_layout占30,status占1
        v_layout->setStretchFactor(h_layout , 30);
        v_layout->setStretchFactor(status , 1);
        widget->setLayout(v_layout);
        this->setCentralWidget(widget);
    /*  @} */

    
}

MainWindow::~MainWindow()
{

}
