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
#include <QtWidgets/QGridLayout>
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
    QAction *actionSetImageRecordPath;
    QAction *actionCalibrate;
    QAction *actionblank_icon;
    QAction *actionSetCalibrationPath;
    QAction *actionCalib_capture;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *displaywindow_1;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *displaywindow_2;
    QGroupBox *groupBox_3;
    QPushButton *set_1;
    QPushButton *set_2;
    QGridLayout *gridLayout_4;
    QTreeWidget *parameter_tree;
    QLabel *label;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(866, 642);
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
        actionSetImageRecordPath = new QAction(MainWindow);
        actionSetImageRecordPath->setObjectName(QStringLiteral("actionSetImageRecordPath"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/iocn/resources/archive.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetImageRecordPath->setIcon(icon4);
        actionCalibrate = new QAction(MainWindow);
        actionCalibrate->setObjectName(QStringLiteral("actionCalibrate"));
        actionCalibrate->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/iocn/resources/calibration.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCalibrate->setIcon(icon5);
        actionblank_icon = new QAction(MainWindow);
        actionblank_icon->setObjectName(QStringLiteral("actionblank_icon"));
        actionSetCalibrationPath = new QAction(MainWindow);
        actionSetCalibrationPath->setObjectName(QStringLiteral("actionSetCalibrationPath"));
        actionSetCalibrationPath->setIcon(icon4);
        actionCalib_capture = new QAction(MainWindow);
        actionCalib_capture->setObjectName(QStringLiteral("actionCalib_capture"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/iocn/resources/capture.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionCalib_capture->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(421, 421));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        displaywindow_1 = new QLabel(groupBox);
        displaywindow_1->setObjectName(QStringLiteral("displaywindow_1"));
        sizePolicy.setHeightForWidth(displaywindow_1->sizePolicy().hasHeightForWidth());
        displaywindow_1->setSizePolicy(sizePolicy);
        displaywindow_1->setMinimumSize(QSize(401, 391));
        displaywindow_1->setAutoFillBackground(false);

        gridLayout_3->addWidget(displaywindow_1, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(421, 421));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        displaywindow_2 = new QLabel(groupBox_2);
        displaywindow_2->setObjectName(QStringLiteral("displaywindow_2"));
        sizePolicy.setHeightForWidth(displaywindow_2->sizePolicy().hasHeightForWidth());
        displaywindow_2->setSizePolicy(sizePolicy);
        displaywindow_2->setMinimumSize(QSize(401, 391));
        displaywindow_2->setAutoFillBackground(false);

        gridLayout_2->addWidget(displaywindow_2, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(841, 131));
        groupBox_3->setMaximumSize(QSize(16777215, 131));
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
        gridLayout_4 = new QGridLayout(groupBox_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
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
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(parameter_tree->sizePolicy().hasHeightForWidth());
        parameter_tree->setSizePolicy(sizePolicy1);
        parameter_tree->setMinimumSize(QSize(821, 101));
        parameter_tree->setMaximumSize(QSize(16777215, 101));
        parameter_tree->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        parameter_tree->setIndentation(0);
        parameter_tree->setExpandsOnDoubleClick(true);
        parameter_tree->setColumnCount(11);
        parameter_tree->header()->setDefaultSectionSize(70);
        parameter_tree->header()->setStretchLastSection(false);

        gridLayout_4->addWidget(parameter_tree, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setIconSize(QSize(50, 35));
        MainWindow->addToolBar(Qt::BottomToolBarArea, mainToolBar);

        mainToolBar->addAction(actionLoad);
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionSetImageRecordPath);
        mainToolBar->addAction(actionRecord);
        mainToolBar->addAction(actionStop);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionblank_icon);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCalibrate);
        mainToolBar->addAction(actionSetCalibrationPath);
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
        actionSetImageRecordPath->setText(QApplication::translate("MainWindow", "SetImageRecordPath", Q_NULLPTR));
        actionCalibrate->setText(QApplication::translate("MainWindow", "Calibrate", Q_NULLPTR));
        actionblank_icon->setText(QString());
        actionSetCalibrationPath->setText(QApplication::translate("MainWindow", "SetCalibrationPath", Q_NULLPTR));
        actionCalib_capture->setText(QApplication::translate("MainWindow", "Calib_capture", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Camera_1", Q_NULLPTR));
        displaywindow_1->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Camera_2", Q_NULLPTR));
        displaywindow_2->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Camera Parameters Setting", Q_NULLPTR));
        set_1->setText(QString());
        set_2->setText(QString());
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

        label->setText(QApplication::translate("MainWindow", "Console", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
