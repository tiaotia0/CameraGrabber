#ifndef CALIBRATIONDIALOG_H
#define CALIBRATIONDIALOG_H

#include <QDialog>

namespace Ui {
	class CalibDialog;
};

class CalibDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CalibDialog(QWidget *parent = 0);
	~CalibDialog();

private slots:
	void on_calibration_close_clicked();

private:
	Ui::CalibDialog *ui;
};
#endif // !CALIBRATIONDIALOG_H

