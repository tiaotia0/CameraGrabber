#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>
#include <QWidget>
#include "siliconboard.h"
#include "imagecontroler.h"

namespace Ui {
	class DisplayWindow;
	class MainWindow;
}
class DisplayWindow : public QWidget
{
	Q_OBJECT

public:
	explicit DisplayWindow(QWidget *parent = 0);
	~DisplayWindow();

public slots:
	void freshWindow(QImage);

private:
	Ui::DisplayWindow *ui;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setParameters(size_t k);
    void showParameters(size_t i);
    QTreeWidgetItem *temItem;
    int temColumn;

private slots:
    void on_load_clicked();
    void on_set_1_clicked();
    void on_set_2_clicked();

    void on_play_clicked();
    void on_stop_clicked();
	void on_record_clicked();
	//void on_calibration_clicked();

    void openEditor_1(QTreeWidgetItem *item, int column);
    void closeEditor_1();
	void openEditor_2(QTreeWidgetItem *item, int column);
	void closeEditor_2();

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
	std::vector<QLineEdit*> status;

	SystemImageCaptureBoards *sysboards = nullptr;
	ImageCaptureBoard *first_board_ptr = nullptr;
	std::vector<Base_ImageContrler*> image_control_ptr_vec;
	std::vector<DisplayWindow *> display_window_ptr_vec;
	//static bool is_recording;
};

#endif // MAINWINDOW_H
