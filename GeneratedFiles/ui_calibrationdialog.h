/********************************************************************************
** Form generated from reading UI file 'calibrationdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATIONDIALOG_H
#define UI_CALIBRATIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_CalibDialog
{
public:
    QLabel *calib_show_1;
    QLabel *calib_show_2;
    QPushButton *calibration_close;
    QTreeWidget *calibration_tree;

    void setupUi(QDialog *CalibDialog)
    {
        if (CalibDialog->objectName().isEmpty())
            CalibDialog->setObjectName(QStringLiteral("CalibDialog"));
        CalibDialog->resize(610, 331);
        calib_show_1 = new QLabel(CalibDialog);
        calib_show_1->setObjectName(QStringLiteral("calib_show_1"));
        calib_show_1->setGeometry(QRect(30, 20, 256, 204));
        calib_show_2 = new QLabel(CalibDialog);
        calib_show_2->setObjectName(QStringLiteral("calib_show_2"));
        calib_show_2->setGeometry(QRect(320, 20, 256, 204));
        calibration_close = new QPushButton(CalibDialog);
        calibration_close->setObjectName(QStringLiteral("calibration_close"));
        calibration_close->setGeometry(QRect(480, 260, 75, 31));
        calibration_tree = new QTreeWidget(CalibDialog);
        calibration_tree->headerItem()->setText(0, QString());
        new QTreeWidgetItem(calibration_tree);
        calibration_tree->setObjectName(QStringLiteral("calibration_tree"));
        calibration_tree->setGeometry(QRect(40, 250, 411, 51));
        calibration_tree->setIndentation(0);

        retranslateUi(CalibDialog);

        QMetaObject::connectSlotsByName(CalibDialog);
    } // setupUi

    void retranslateUi(QDialog *CalibDialog)
    {
        CalibDialog->setWindowTitle(QApplication::translate("CalibDialog", "Dialog", Q_NULLPTR));
        calib_show_1->setText(QApplication::translate("CalibDialog", "TextLabel", Q_NULLPTR));
        calib_show_2->setText(QApplication::translate("CalibDialog", "TextLabel", Q_NULLPTR));
        calibration_close->setText(QApplication::translate("CalibDialog", "Close", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem = calibration_tree->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("CalibDialog", "Total Progress", Q_NULLPTR));
        ___qtreewidgetitem->setText(2, QApplication::translate("CalibDialog", "Camera_2", Q_NULLPTR));
        ___qtreewidgetitem->setText(1, QApplication::translate("CalibDialog", "Camera_1", Q_NULLPTR));

        const bool __sortingEnabled = calibration_tree->isSortingEnabled();
        calibration_tree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = calibration_tree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("CalibDialog", "Calibration Status", Q_NULLPTR));
        calibration_tree->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class CalibDialog: public Ui_CalibDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATIONDIALOG_H
