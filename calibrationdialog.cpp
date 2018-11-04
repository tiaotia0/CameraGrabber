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
	//�궨
	cv::Mat imageInput;
	//ͼƬ�ϸ���ʾͼƬ

	QImage calib_show = QImage((const unsigned char*)(imageInput.data),
		imageInput.cols, imageInput.rows,
		imageInput.cols*imageInput.channels(),
		QImage::Format_Indexed8);
	ui->calib_show_1->setPixmap(QPixmap::fromImage(calib_show));
	ui->textEdit->setText(QString::number(frameNumber) + " frames have been captured.\n");

	//ͼƬ���ϸ�
	ui->textEdit->setText(QString::number(frameNumber) + " frames have been captured.\n");
	ui->textEdit->append("The image is bad please try again");
}

void CalibDialog::on_finish_clicked()
{
	//��ɱ궨

	//��ʾ���
}