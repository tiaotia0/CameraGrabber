/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionPlay;
    QAction *actionRecord;
    QAction *actionStop;
    QAction *actionSetImagePath;
    QAction *actionCalibrate;
    QAction *actionblank_icon;
    QAction *actionSetCalibPath;
    QAction *actionCalib_capture;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLabel *displaywindow_1;
    QGroupBox *groupBox_2;
    QLabel *displaywindow_2;
    QGroupBox *groupBox_3;
    QTreeWidget *parameter_tree;
    QPushButton *set_1;
    QPushButton *set_2;
    QLabel *label;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(861, 642);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionLoad->setCheckable(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/iocn/resources/load1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon);
        QFont font;
        actionLoad->setFont(font);
        actionLoad->setVisible(true);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QStringLiteral("actionPlay"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/iocn/resources/play1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon1);
        actionRecord = new QAction(MainWindow);
        actionRecord->setObjectName(QStringLiteral("actionRecord"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/iocn/resources/record1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionRecord->setIcon(icon2);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/iocn/resources/stop1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon3);
        actionSetImagePath = new QAction(MainWindow);
        actionSetImagePath->setObjectName(QStringLiteral("actionSetImagePath"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/iocn/resources/archive.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetImagePath->setIcon(icon4);
        actionCalibrate = new QAction(MainWindow);
        actionCalibrate->setObjectName(QStringLiteral("actionCalibrate"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/iocn/resources/calibration.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCalibrate->setIcon(icon5);
        actionblank_icon = new QAction(MainWindow);
        actionblank_icon->setObjectName(QStringLiteral("actionblank_icon"));
        actionSetCalibPath = new QAction(MainWindow);
        actionSetCalibPath->setObjectName(QStringLiteral("actionSetCalibPath"));
        actionSetCalibPath->setIcon(icon4);
        actionCalib_capture = new QAction(MainWindow);
        actionCalib_capture->setObjectName(QStringLiteral("actionCalib_capture"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/iocn/resources/capture.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCalib_capture->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 421, 421));
        displaywindow_1 = new QLabel(groupBox);
        displaywindow_1->setObjectName(QStringLiteral("displaywindow_1"));
        displaywindow_1->setGeometry(QRect(10, 20, 401, 391));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(430, 10, 421, 421));
        displaywindow_2 = new QLabel(groupBox_2);
        displaywindow_2->setObjectName(QStringLiteral("displaywindow_2"));
        displaywindow_2->setGeometry(QRect(10, 20, 401, 391));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 430, 841, 131));
        parameter_tree = new QTreeWidget(groupBox_3);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(10, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(9, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(8, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(7, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(6, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(5, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(4, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(3, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(2, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem->setTextAlignment(0, Qt::AlignCenter);
        parameter_tree->setHeaderItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(parameter_tree);
        __qtreewidgetitem1->setTextAlignment(9, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(8, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(7, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(6, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(5, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(4, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(3, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(2, Qt::AlignCenter);
        __qtreewidgetitem1->setTextAlignment(1, Qt::AlignCenter);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(parameter_tree);
        __qtreewidgetitem2->setTextAlignment(9, Qt::AlignCenter);
        __qtreewidgetitem2->setTextAlignment(8, Qt::AlignCenter);
        __qtreewidgetitem2->setTextAlignment(7, Qt::AlignCenter);
        __qtreewidgetitem2->setTextAlignment(6, Qt::AlignCenter);
        __qtreewidgetitem2->setTextAlignment(5, Qt::AlignCenter);
        __qtreewidgetitem2->setTextAlignment(4, Qt::AlignCenter);
        __qtreewidgetitem2->setTextAlignment(3, Qt::AlignCenter);
        __qtreewidgetitem2->setTextAlignment(2, Qt::AlignCenter);
        __qtreewidgetitem2->setTextAlignment(1, Qt::AlignCenter);
        parameter_tree->setObjectName(QStringLiteral("parameter_tree"));
        parameter_tree->setEnabled(true);
        parameter_tree->setGeometry(QRect(10, 20, 821, 101));
        parameter_tree->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        parameter_tree->setIndentation(0);
        parameter_tree->setExpandsOnDoubleClick(true);
        parameter_tree->setColumnCount(11);
        parameter_tree->header()->setDefaultSectionSize(70);
        parameter_tree->header()->setStretchLastSection(false);
        set_1 = new QPushButton(groupBox_3);
        set_1->setObjectName(QStringLiteral("set_1"));
        set_1->setEnabled(false);
        set_1->setGeometry(QRect(730, 40, 51, 41));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/iocn/resources/upload_para1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        set_1->setIcon(icon7);
        set_1->setIconSize(QSize(20, 20));
        set_2 = new QPushButton(groupBox_3);
        set_2->setObjectName(QStringLiteral("set_2"));
        set_2->setEnabled(false);
        set_2->setGeometry(QRect(730, 80, 51, 41));
        set_2->setIcon(icon7);
        set_2->setIconSize(QSize(20, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 580, 54, 12));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setIconSize(QSize(50, 35));
        MainWindow->addToolBar(Qt::BottomToolBarArea, mainToolBar);

        mainToolBar->addAction(actionLoad);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionSetImagePath);
        mainToolBar->addAction(actionRecord);
        mainToolBar->addAction(actionStop);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionblank_icon);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCalibrate);
        mainToolBar->addAction(actionSetCalibPath);
        mainToolBar->addAction(actionCalib_capture);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", Q_NULLPTR));
        actionRecord->setText(QApplication::translate("MainWindow", "Record", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRecord->setToolTip(QApplication::translate("MainWindow", "Record", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        actionSetImagePath->setText(QApplication::translate("MainWindow", "SetImagePath", Q_NULLPTR));
        actionCalibrate->setText(QApplication::translate("MainWindow", "Calibrate", Q_NULLPTR));
        actionblank_icon->setText(QString());
        actionSetCalibPath->setText(QApplication::translate("MainWindow", "SetCalibPath", Q_NULLPTR));
        actionCalib_capture->setText(QApplication::translate("MainWindow", "calib_capture", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Camera_1", Q_NULLPTR));
        displaywindow_1->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Camera_2", Q_NULLPTR));
        displaywindow_2->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Camera Parameters Setting", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = parameter_tree->headerItem();
        ___qtreewidgetitem->setText(10, QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        ___qtreewidgetitem->setText(9, QApplication::translate("MainWindow", "   CL freq   ", Q_NULLPTR));
        ___qtreewidgetitem->setText(8, QApplication::translate("MainWindow", "   CL mode   ", Q_NULLPTR));
        ___qtreewidgetitem->setText(7, QApplication::translate("MainWindow", "    Polarity    ", Q_NULLPTR));
        ___qtreewidgetitem->setText(6, QApplication::translate("MainWindow", "    Trigger    ", Q_NULLPTR));
        ___qtreewidgetitem->setText(5, QApplication::translate("MainWindow", "  Exposure  ", Q_NULLPTR));
        ___qtreewidgetitem->setText(4, QApplication::translate("MainWindow", "   FPS   ", Q_NULLPTR));
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindow", "   Height   ", Q_NULLPTR));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindow", "   Width   ", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Status", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Camera", Q_NULLPTR));

        const bool __sortingEnabled = parameter_tree->isSortingEnabled();
        parameter_tree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = parameter_tree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Camera_1", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = parameter_tree->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Camera_2", Q_NULLPTR));
        parameter_tree->setSortingEnabled(__sortingEnabled);

        set_1->setText(QString());
        set_2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Console", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
