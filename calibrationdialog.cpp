#include "calibrationdialog.h"
#include "ui_calibrationdialog.h"
#include "ui_cali_para_set_dialog.h"

CalibDialog::CalibDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CalibDialog)
{
	ui->setupUi(this);
	//ui->label->setScaledContents(true);
}

CalibDialog::~CalibDialog()
{
	delete ui;
}

void CalibDialog::on_calibration_close_clicked()
{
	this->close();
}

void CalibDialog::showCalibImage_1(QImage qImg)
{
	ui->calib_show_1->setPixmap(QPixmap::fromImage(qImg));
}

void CalibDialog::showCalibImage_2(QImage qImg)
{
	ui->calib_show_2->setPixmap(QPixmap::fromImage(qImg));
}

void CalibDialog::showCalibStatus(QVector<QString> calib_status)
{
	ui->calibration_tree->topLevelItem(0)->setText(0, calib_status[0]);
	ui->calibration_tree->topLevelItem(0)->setText(1, calib_status[1]);
	ui->calibration_tree->topLevelItem(0)->setText(2, calib_status[2]);
}

CaliParaSetDialog::CaliParaSetDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CaliParaSetDialog)
{
	ui->setupUi(this);
}

CaliParaSetDialog::~CaliParaSetDialog()
{
	delete ui;
}


void CaliParaSetDialog::on_cali_set_btn_clicked()
{
	CaliParameter cali_para;
	cali_para.CornerAmountAlongWidth = ui->CornerAmountAlongWidth->text().toInt();
	cali_para.CornerAmountAlongHeight = ui->CornerAmountAlongHeight->text().toInt();
	cali_para.DistanceBetweenCorners = ui->DistanceBetweenCorners->text().toInt();
	cali_para.PictureAmount = ui->PictureAmount->text().toInt();
	cali_para.CalibrationBoardType = 0;
	if (ui->CalibrationBoardType->currentText() == "CircleGrid")
		cali_para.CalibrationBoardType = 0;
	else if (ui->CalibrationBoardType->currentText() == "ChessBoard")
		cali_para.CalibrationBoardType = 1;

	emit sendCaliParameter(cali_para);
	this->close();
}