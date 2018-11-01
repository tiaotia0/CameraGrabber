#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "siliconboard.h"
#include "imagedisplaycontroler.h"

#include <QMainWindow>
#include <QTreeWidget>
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>

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

    QTreeWidgetItem *temItem;
    int temColumn;
	bool isloaded;

signals:
    //void sendImage();

private slots:
    void on_load_clicked();
    void on_set_1_clicked();
    void on_set_2_clicked();
    void showImage_1(QImage qImg);
    void showImage_2(QImage qImg);

    void on_start_clicked();

    void on_stop_clicked();

    void on_pause_clicked();
    void openEditor_1(QTreeWidgetItem *item, int column);
    void closeEditor_1();
	void openEditor_2(QTreeWidgetItem *item, int column);
	void closeEditor_2();


private:
    Ui::MainWindow *ui;
    CameraParameters para;
    ImageCaptureBoard *global_board_ptr;
	SystemImageCaptureBoards sysboards;

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
    std::vector<Base_ImageContrler*> v;
    std::vector<QLabel*> display_window;
	std::vector<QPushButton*> set_vec;
	std::vector<QLineEdit*> status;

    ImageDisplayControler *imagedisplay;

};

#endif // MAINWINDOW_H
