#include "calibrationdialog.h"
#include "ui_calibrationdialog.h"

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
