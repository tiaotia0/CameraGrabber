#ifndef CALIBRATIONDIALOG_H
#define CALIBRATIONDIALOG_H

#include <QDialog>
#include <QMetaType>

struct CaliParameter
{
	int CornerAmountAlongWidth;
	int CornerAmountAlongHeight;
	int DistanceBetweenCorners;
	int PictureAmount;
	int CalibrationBoardType;
};
Q_DECLARE_METATYPE(CaliParameter)

namespace Ui {
	class CalibDialog;
	class CaliParaSetDialog;
};

class CalibDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CalibDialog(QWidget *parent = 0);
	~CalibDialog();

private slots:
	void on_calibration_close_clicked();
	void showCalibImage_1(QImage qImg);
	void showCalibImage_2(QImage qImg);
	void showCalibStatus(QVector<QString> calib_status);
private:
	Ui::CalibDialog *ui;
};

class CaliParaSetDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CaliParaSetDialog(QWidget *parent = 0);
	~CaliParaSetDialog();

signals:
	void sendCaliParameter(CaliParameter cali_para);

private slots:
	void on_cali_set_btn_clicked();

private:
	Ui::CaliParaSetDialog *ui;

};
#endif // !CALIBRATIONDIALOG_H

