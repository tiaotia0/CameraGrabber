/********************************************************************************
** Form generated from reading UI file 'cali_para_set_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALI_PARA_SET_DIALOG_H
#define UI_CALI_PARA_SET_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CaliParaSetDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *CornerAmountAlongWidth;
    QLabel *label_2;
    QLineEdit *CornerAmountAlongHeight;
    QLabel *label_3;
    QLineEdit *DistanceBetweenCorners;
    QLabel *label_4;
    QLineEdit *PictureAmount;
    QLabel *label_5;
    QComboBox *CalibrationBoardType;
    QPushButton *cali_set_btn;

    void setupUi(QDialog *CaliParaSetDialog)
    {
        if (CaliParaSetDialog->objectName().isEmpty())
            CaliParaSetDialog->setObjectName(QStringLiteral("CaliParaSetDialog"));
        CaliParaSetDialog->resize(249, 300);
        gridLayout = new QGridLayout(CaliParaSetDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(CaliParaSetDialog);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        CornerAmountAlongWidth = new QLineEdit(CaliParaSetDialog);
        CornerAmountAlongWidth->setObjectName(QStringLiteral("CornerAmountAlongWidth"));

        gridLayout->addWidget(CornerAmountAlongWidth, 0, 2, 1, 1);

        label_2 = new QLabel(CaliParaSetDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        CornerAmountAlongHeight = new QLineEdit(CaliParaSetDialog);
        CornerAmountAlongHeight->setObjectName(QStringLiteral("CornerAmountAlongHeight"));

        gridLayout->addWidget(CornerAmountAlongHeight, 1, 2, 1, 1);

        label_3 = new QLabel(CaliParaSetDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        DistanceBetweenCorners = new QLineEdit(CaliParaSetDialog);
        DistanceBetweenCorners->setObjectName(QStringLiteral("DistanceBetweenCorners"));

        gridLayout->addWidget(DistanceBetweenCorners, 2, 2, 1, 1);

        label_4 = new QLabel(CaliParaSetDialog);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 2);

        PictureAmount = new QLineEdit(CaliParaSetDialog);
        PictureAmount->setObjectName(QStringLiteral("PictureAmount"));

        gridLayout->addWidget(PictureAmount, 3, 2, 1, 1);

        label_5 = new QLabel(CaliParaSetDialog);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 2);

        CalibrationBoardType = new QComboBox(CaliParaSetDialog);
        CalibrationBoardType->setObjectName(QStringLiteral("CalibrationBoardType"));

        gridLayout->addWidget(CalibrationBoardType, 4, 2, 1, 1);

        cali_set_btn = new QPushButton(CaliParaSetDialog);
        cali_set_btn->setObjectName(QStringLiteral("cali_set_btn"));

        gridLayout->addWidget(cali_set_btn, 5, 1, 1, 2);


        retranslateUi(CaliParaSetDialog);

        QMetaObject::connectSlotsByName(CaliParaSetDialog);
    } // setupUi

    void retranslateUi(QDialog *CaliParaSetDialog)
    {
        CaliParaSetDialog->setWindowTitle(QApplication::translate("CaliParaSetDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("CaliParaSetDialog", "CornerAmountAlongWidth", Q_NULLPTR));
        CornerAmountAlongWidth->setText(QApplication::translate("CaliParaSetDialog", "0", Q_NULLPTR));
        label_2->setText(QApplication::translate("CaliParaSetDialog", "CornerAmountAlongHeight", Q_NULLPTR));
        CornerAmountAlongHeight->setText(QApplication::translate("CaliParaSetDialog", "0", Q_NULLPTR));
        label_3->setText(QApplication::translate("CaliParaSetDialog", "DistanceBetweenCorners", Q_NULLPTR));
        DistanceBetweenCorners->setText(QApplication::translate("CaliParaSetDialog", "0", Q_NULLPTR));
        label_4->setText(QApplication::translate("CaliParaSetDialog", "PictureAmount", Q_NULLPTR));
        PictureAmount->setText(QApplication::translate("CaliParaSetDialog", "12", Q_NULLPTR));
        label_5->setText(QApplication::translate("CaliParaSetDialog", "CalibrationBoardType", Q_NULLPTR));
        CalibrationBoardType->clear();
        CalibrationBoardType->insertItems(0, QStringList()
         << QApplication::translate("CaliParaSetDialog", "CircleGrid", Q_NULLPTR)
         << QApplication::translate("CaliParaSetDialog", "ChessBoard", Q_NULLPTR)
        );
        cali_set_btn->setText(QApplication::translate("CaliParaSetDialog", "Set", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CaliParaSetDialog: public Ui_CaliParaSetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALI_PARA_SET_DIALOG_H
