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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *load;
    QPushButton *play;
    QPushButton *stop;
    QPushButton *record;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *status_1;
    QPushButton *set_1;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *status_2;
    QPushButton *set_2;
    QPushButton *recover;
    QTreeWidget *parameter_1;
    QTreeWidget *parameter_2;
    QMdiArea *mdiArea_1;
    QMdiArea *mdiArea_2;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(779, 625);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        load = new QPushButton(centralWidget);
        load->setObjectName(QStringLiteral("load"));
        load->setGeometry(QRect(20, 10, 80, 20));
        play = new QPushButton(centralWidget);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(130, 10, 80, 20));
        stop = new QPushButton(centralWidget);
        stop->setObjectName(QStringLiteral("stop"));
        stop->setGeometry(QRect(330, 10, 80, 20));
        record = new QPushButton(centralWidget);
        record->setObjectName(QStringLiteral("record"));
        record->setGeometry(QRect(430, 10, 80, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 50, 231, 25));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        status_1 = new QLineEdit(layoutWidget);
        status_1->setObjectName(QStringLiteral("status_1"));

        horizontalLayout_2->addWidget(status_1);

        set_1 = new QPushButton(layoutWidget);
        set_1->setObjectName(QStringLiteral("set_1"));
        set_1->setEnabled(false);

        horizontalLayout_2->addWidget(set_1);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 310, 231, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        status_2 = new QLineEdit(layoutWidget1);
        status_2->setObjectName(QStringLiteral("status_2"));

        horizontalLayout->addWidget(status_2);

        set_2 = new QPushButton(layoutWidget1);
        set_2->setObjectName(QStringLiteral("set_2"));
        set_2->setEnabled(false);

        horizontalLayout->addWidget(set_2);

        recover = new QPushButton(centralWidget);
        recover->setObjectName(QStringLiteral("recover"));
        recover->setGeometry(QRect(540, 10, 80, 20));
        parameter_1 = new QTreeWidget(centralWidget);
        new QTreeWidgetItem(parameter_1);
        new QTreeWidgetItem(parameter_1);
        new QTreeWidgetItem(parameter_1);
        new QTreeWidgetItem(parameter_1);
        new QTreeWidgetItem(parameter_1);
        new QTreeWidgetItem(parameter_1);
        new QTreeWidgetItem(parameter_1);
        new QTreeWidgetItem(parameter_1);
        parameter_1->setObjectName(QStringLiteral("parameter_1"));
        parameter_1->setEnabled(false);
        parameter_1->setGeometry(QRect(20, 80, 241, 211));
        parameter_1->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        parameter_1->setIndentation(10);
        parameter_1->setExpandsOnDoubleClick(true);
        parameter_1->setColumnCount(2);
        parameter_1->header()->setDefaultSectionSize(120);
        parameter_2 = new QTreeWidget(centralWidget);
        new QTreeWidgetItem(parameter_2);
        new QTreeWidgetItem(parameter_2);
        new QTreeWidgetItem(parameter_2);
        new QTreeWidgetItem(parameter_2);
        new QTreeWidgetItem(parameter_2);
        new QTreeWidgetItem(parameter_2);
        new QTreeWidgetItem(parameter_2);
        new QTreeWidgetItem(parameter_2);
        parameter_2->setObjectName(QStringLiteral("parameter_2"));
        parameter_2->setEnabled(false);
        parameter_2->setGeometry(QRect(20, 340, 241, 211));
        parameter_2->setIndentation(10);
        parameter_2->setColumnCount(2);
        parameter_2->header()->setDefaultSectionSize(120);
        mdiArea_1 = new QMdiArea(centralWidget);
        mdiArea_1->setObjectName(QStringLiteral("mdiArea_1"));
        mdiArea_1->setGeometry(QRect(290, 60, 400, 231));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mdiArea_1->sizePolicy().hasHeightForWidth());
        mdiArea_1->setSizePolicy(sizePolicy);
        mdiArea_2 = new QMdiArea(centralWidget);
        mdiArea_2->setObjectName(QStringLiteral("mdiArea_2"));
        mdiArea_2->setGeometry(QRect(290, 320, 400, 231));
        sizePolicy.setHeightForWidth(mdiArea_2->sizePolicy().hasHeightForWidth());
        mdiArea_2->setSizePolicy(sizePolicy);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 779, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        load->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        play->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        stop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        record->setText(QApplication::translate("MainWindow", "Record", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Camera_1", Q_NULLPTR));
        status_1->setText(QApplication::translate("MainWindow", "Disconnected", Q_NULLPTR));
        set_1->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Camera_2", Q_NULLPTR));
        status_2->setText(QApplication::translate("MainWindow", "Disconnected", Q_NULLPTR));
        set_2->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        recover->setText(QApplication::translate("MainWindow", "Recover", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = parameter_1->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "Parameter", Q_NULLPTR));

        const bool __sortingEnabled = parameter_1->isSortingEnabled();
        parameter_1->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = parameter_1->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Width", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = parameter_1->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Height", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = parameter_1->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Frame rate", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = parameter_1->topLevelItem(3);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Exposure time", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = parameter_1->topLevelItem(4);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Trigger mode", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = parameter_1->topLevelItem(5);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Polarity", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem7 = parameter_1->topLevelItem(6);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "CL mode", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem8 = parameter_1->topLevelItem(7);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "CL frequency", Q_NULLPTR));
        parameter_1->setSortingEnabled(__sortingEnabled);

        QTreeWidgetItem *___qtreewidgetitem9 = parameter_2->headerItem();
        ___qtreewidgetitem9->setText(1, QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "Parameter", Q_NULLPTR));

        const bool __sortingEnabled1 = parameter_2->isSortingEnabled();
        parameter_2->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem10 = parameter_2->topLevelItem(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "Width", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem11 = parameter_2->topLevelItem(1);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "Height", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem12 = parameter_2->topLevelItem(2);
        ___qtreewidgetitem12->setText(0, QApplication::translate("MainWindow", "Frame rate", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem13 = parameter_2->topLevelItem(3);
        ___qtreewidgetitem13->setText(0, QApplication::translate("MainWindow", "Exposure time", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem14 = parameter_2->topLevelItem(4);
        ___qtreewidgetitem14->setText(0, QApplication::translate("MainWindow", "Trigger mode", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem15 = parameter_2->topLevelItem(5);
        ___qtreewidgetitem15->setText(0, QApplication::translate("MainWindow", "Polarity", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem16 = parameter_2->topLevelItem(6);
        ___qtreewidgetitem16->setText(0, QApplication::translate("MainWindow", "CL mode", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem17 = parameter_2->topLevelItem(7);
        ___qtreewidgetitem17->setText(0, QApplication::translate("MainWindow", "CL frequency", Q_NULLPTR));
        parameter_2->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
