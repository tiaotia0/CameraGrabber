#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>
#include <QWidget>
#include <QFileDialog>
#include <QPushButton>
#include "siliconboard.h"
#include "imgprocesscontroler.h"
#include "cv_calibration.h"
#include "calibrationdialog.h"


namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setParameters(size_t k);
    void showParameters(size_t i);
    QTreeWidgetItem *temItem = nullptr;
    int temColumn;

private slots:
    void on_set_1_clicked();
    void on_set_2_clicked();

    void openEditor(QTreeWidgetItem *item, int column);
    void closeEditor();

    void on_actionLoad_triggered();
    void on_actionPlay_triggered();
    void on_actionSetImageRecordPath_triggered();
	void on_actionSetCalibPath_triggered();
    void on_actionStop_triggered();
    void on_actionRecord_triggered();
	void on_actionCalibrate_triggered();
	void on_actionCalib_capture_triggered();

	void showImage_1(QImage qImg);
	void showImage_2(QImage qImg);

	void receiveCaliParameter(CaliParameter cali_para);
	void CalibAndShow();


private:
    Ui::MainWindow *ui;

    QComboBox *synchro_box_1;
    QComboBox *polarity_box_1;
    QComboBox *clmode_box_1;
    QComboBox *clfrequency_box_1;
    QComboBox *synchro_box_2;
    QComboBox *polarity_box_2;
    QComboBox *clmode_box_2;
    QComboBox *clfrequency_box_2;
    std::vector<QTreeWidget*> parameterTree;
    std::vector<QComboBox*> synchro_vec;
    std::vector<QComboBox*> polarity_vec;
    std::vector<QComboBox*> clmode_vec;
    std::vector<QComboBox*> clfrequency_vec;
    std::vector<QLabel*> display_window;
	std::vector<QPushButton*> set_vec;

	std::string images_savefolder;
	std::string calibrate_savefolder;
	SystemImageCaptureBoards *sysboards = nullptr;
	ImageCaptureBoard *first_board_ptr = nullptr;
	std::vector<ImageDisplayControler*> image_control_ptr_vec;
	CaliParameter calibrate_para;
	CameraCalibrateControler *calibrator_ptr = nullptr;

	QPushButton* status_1;
	QPushButton* status_2;
};

#endif // MAINWINDOW_H
