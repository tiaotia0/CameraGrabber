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

void CalibDialog::on_next_clicked()
{
	//标定
	cv::Mat imageInput;
	//图片合格，显示图片

	QImage calib_show = QImage((const unsigned char*)(imageInput.data),
		imageInput.cols, imageInput.rows,
		imageInput.cols*imageInput.channels(),
		QImage::Format_Indexed8);
	ui->calib_show_1->setPixmap(QPixmap::fromImage(calib_show));
	ui->textEdit->setText(QString::number(frameNumber) + " frames have been captured.\n");

	//图片不合格
	ui->textEdit->setText(QString::number(frameNumber) + " frames have been captured.\n");
	ui->textEdit->append("The image is bad please try again");
}

void CalibDialog::on_finish_clicked()
{
	//完成标定

	//显示结果
}