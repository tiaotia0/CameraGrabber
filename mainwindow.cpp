#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calibrationdialog.h"
#include <direct.h>
#include<fstream>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    synchro_box_1 = new QComboBox;
    polarity_box_1 = new QComboBox;
    clmode_box_1 = new QComboBox;
    clfrequency_box_1 = new QComboBox;
    synchro_box_2 = new QComboBox;
    polarity_box_2 = new QComboBox;
    clmode_box_2 = new QComboBox;
    clfrequency_box_2 = new QComboBox;

	synchro_vec = { this->synchro_box_1, this->synchro_box_2 };
	polarity_vec = { this->polarity_box_1, this->polarity_box_2 };
	clmode_vec = { this->clmode_box_1, this->clmode_box_2 };
	clfrequency_vec = { this->clfrequency_box_1, this->clfrequency_box_2 };
	set_vec = { ui->set_1, ui->set_2 };

	for (size_t i = 0; i <= 1; i++) {
		synchro_vec[i]->addItem("Intern");
		synchro_vec[i]->addItem("Extern");
		polarity_vec[i]->addItem("Positive edge");
		polarity_vec[i]->addItem("Positive level");
		polarity_vec[i]->addItem("Negative edge");
		polarity_vec[i]->addItem("Negative level");
		clmode_vec[i]->addItem("2×8 bits");
		clmode_vec[i]->addItem("2×10 bits");
		clfrequency_vec[i]->addItem("66MHz");
		clfrequency_vec[i]->addItem("75MHz");
		clfrequency_vec[i]->addItem("85MHz");
	}

    connect(ui->parameter_tree,SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(openEditor(QTreeWidgetItem*, int)));
    connect(ui->parameter_tree,SIGNAL(itemSelectionChanged()), this, SLOT(closeEditor()));

    ui->parameter_tree->setStyleSheet("QTreeWidget::item{height:30px}");

	ui->set_1->setStyleSheet("background-color:transparent");
	ui->set_2->setStyleSheet("background-color:transparent");

	ui->parameter_tree->setItemWidget(ui->parameter_tree->topLevelItem(0), 10, ui->set_1);
	ui->parameter_tree->setItemWidget(ui->parameter_tree->topLevelItem(1), 10, ui->set_2);

	status_1 = new QPushButton;
	status_2 = new QPushButton;
	status_1->setText("Port A");
	status_2->setText("Port B");
	this->status_1->setStyleSheet("background-color:red");
	this->status_2->setStyleSheet("background-color:red");
	ui->parameter_tree->setItemWidget(ui->parameter_tree->topLevelItem(0), 1, this->status_1);
	ui->parameter_tree->setItemWidget(ui->parameter_tree->topLevelItem(1), 1, this->status_2);

	QHeaderView *head = ui->parameter_tree->header();
	head->setSectionResizeMode(QHeaderView::ResizeToContents);

	ui->displaywindow_1->setScaledContents(true);
	ui->displaywindow_2->setScaledContents(true);

	ui->actionLoad->setDisabled(false);
	ui->actionPlay->setDisabled(true);
	ui->actionSetImageRecordPath->setDisabled(true);
	ui->actionRecord->setDisabled(true);
	ui->actionStop->setDisabled(true);
	ui->actionCalibrate->setDisabled(true);
	ui->actionSetCalibrationPath->setDisabled(true);
	ui->actionCalib_capture->setDisabled(true);

}

MainWindow::~MainWindow()
{
	delete sysboards;
	sysboards = nullptr;
    delete ui;
}

void MainWindow::showParameters(size_t i)
{
	Base_ImageContrler *img_ctrl_ptr = image_control_ptr_vec[i];
    auto para = img_ctrl_ptr->GetCameraParameter();
    ui->parameter_tree->topLevelItem(i)->setText(2, QString::fromStdString(para.m_ImageWidth));
    ui->parameter_tree->topLevelItem(i)->setText(3, QString::fromStdString(para.m_ImageHeight));
    ui->parameter_tree->topLevelItem(i)->setText(4, QString::fromStdString(para.m_FrameFrequency));
    ui->parameter_tree->topLevelItem(i)->setText(5, QString::fromStdString(para.m_ExposureTime));

    ui->parameter_tree->setItemWidget(ui->parameter_tree->topLevelItem(i), 6, synchro_vec[i]);
    ui->parameter_tree->setItemWidget(ui->parameter_tree->topLevelItem(i), 7, polarity_vec[i]);
    ui->parameter_tree->setItemWidget(ui->parameter_tree->topLevelItem(i), 8, clmode_vec[i]);
    ui->parameter_tree->setItemWidget(ui->parameter_tree->topLevelItem(i), 9, clfrequency_vec[i]);

    synchro_vec[i]->setCurrentText(QString::fromStdString(para.m_Synchro));
    polarity_vec[i]->setCurrentText(QString::fromStdString(para.m_Polarity));
    clmode_vec[i]->setCurrentText(QString::fromStdString(para.m_CLMode));
    clfrequency_vec[i]->setCurrentText(QString::fromStdString(para.m_CameraLinkFrequency));

    ui->parameter_tree->topLevelItem(i)->setText(6, QString::fromStdString(para.m_Synchro));
    ui->parameter_tree->topLevelItem(i)->setText(7, QString::fromStdString(para.m_Polarity));
    ui->parameter_tree->topLevelItem(i)->setText(8, QString::fromStdString(para.m_CLMode));
    ui->parameter_tree->topLevelItem(i)->setText(9, QString::fromStdString(para.m_CameraLinkFrequency));
}

void MainWindow::setParameters(size_t k)
{
    QString width = ui->parameter_tree->topLevelItem(k)->text(2);
    QString height = ui->parameter_tree->topLevelItem(k)->text(3);
    QString frameRate = ui->parameter_tree->topLevelItem(k)->text(4);
    QString exposure = ui->parameter_tree->topLevelItem(k)->text(5);
	QString synchro = synchro_vec[k]->currentText();
	QString polarity = polarity_vec[k]->currentText();
	QString clmode = clmode_vec[k]->currentText();
	QString clfrequency = clfrequency_vec[k]->currentText();

	CameraParameters cam_para;
	cam_para.m_ImageWidth = width.toStdString();
	cam_para.m_ImageHeight = height.toStdString();
	cam_para.m_ExposureTime = exposure.toStdString();
	cam_para.m_FrameFrequency = frameRate.toStdString();
	if (synchro == "Intern")
		cam_para.m_Synchro = std::string("0");
	else if (synchro == "Extern")
		cam_para.m_Synchro = std::string("1");

	if (polarity == "Positive edge")
		cam_para.m_Polarity = std::string("11");
	else if (polarity == "Positive level")
		cam_para.m_Polarity = std::string("10");
	else if (polarity == "Negative edge")
		cam_para.m_Polarity = std::string("01");
	else if (polarity == "Negative level")
		cam_para.m_Polarity = std::string("00");

	if (clmode == "2×8 bits")
		cam_para.m_CLMode = std::string("0");
	else if (clmode == "2×10 bits")
		cam_para.m_CLMode = std::string("1");

	if (clfrequency == "66MHz")
		cam_para.m_CameraLinkFrequency = std::string("0");
	else if (clfrequency == "75MHz")
		cam_para.m_CameraLinkFrequency = std::string("1");
	else if (clfrequency == "85MHz")
		cam_para.m_CameraLinkFrequency = std::string("2");
	
	first_board_ptr->RefreshPortConnectStatus();
	auto CameraConnectStatus = first_board_ptr->GetCameraConnectStatus();
	
    for (size_t i = 0; i < image_control_ptr_vec.size(); i++)
    {
		if (!CameraConnectStatus[i]) continue;
		image_control_ptr_vec[i]->SetCameraParameter(cam_para);
        showParameters(i);
    }
}

void MainWindow::on_set_1_clicked()
{
	setParameters(0);
}

void MainWindow::on_set_2_clicked()
{
	setParameters(1);
}

void MainWindow::openEditor(QTreeWidgetItem *item, int column)
{
	if (column == 2 || column == 3 || column == 4 || column == 5)
    {
        ui->parameter_tree->openPersistentEditor(item, column);
        temItem = item;
		temColumn = column;
    }
}

void MainWindow::closeEditor()
{
	if (temItem != nullptr)
    {
        ui->parameter_tree->closePersistentEditor(temItem, temColumn);
    }
}

void MainWindow::on_actionLoad_triggered()
{
    if (sysboards!=nullptr)
    {
        for (auto &item : image_control_ptr_vec)
        {
			if (item == nullptr) continue;
            item->Stop_Acquire();
        }
        delete sysboards;
        sysboards = nullptr;
    }
    sysboards = new SystemImageCaptureBoards;
    sysboards->InitialSystemImageCaptureBoards();
    //默认取第一块采集卡，当有多张采集卡时再更改
    if (sysboards->GetBoardsAmount() > 0)
    {
        first_board_ptr = &(sysboards->GetImageCaptureBoardRefbyIndex(0));
    }
    first_board_ptr->RefreshPortConnectStatus();
    auto CameraConnectStatus = first_board_ptr->GetCameraConnectStatus();
    for (size_t i = 0; i < first_board_ptr->GetBoardPortAmount(); i++)
    {
        if (!CameraConnectStatus[i])
        {
            set_vec[i]->setEnabled(false);
            continue;
        }
		if (i == 0)
			this->status_1->setStyleSheet("background-color:green");
		else
			this->status_2->setStyleSheet("background-color:green");
        set_vec[i]->setEnabled(true);
    }
    image_control_ptr_vec = std::vector<ImageDisplayControler*>(first_board_ptr->GetBoardPortAmount(), nullptr);
    for (size_t i = 0; i < CameraConnectStatus.size(); i++)
    {
        if (CameraConnectStatus[i] && image_control_ptr_vec[i] == nullptr)
        {
            auto tmp_ptr = new ImageDisplayControler(*first_board_ptr, i);
            image_control_ptr_vec[i] = tmp_ptr;
			if (i == 0)
			{
				connect(tmp_ptr, SIGNAL(sendDisplayImage(QImage)), this, SLOT(showImage_1(QImage)));
			}
			else
			{
				connect(tmp_ptr, SIGNAL(sendDisplayImage(QImage)), this, SLOT(showImage_2(QImage)));
			}
            showParameters(i);
			tmp_ptr->FreshCameraParametersToImageCaptureBoard();
        }
    }
	ui->actionLoad->setDisabled(false);
	ui->actionPlay->setDisabled(false);
}

void MainWindow::showImage_1(QImage qImg)
{
	ui->displaywindow_1->setPixmap(QPixmap::fromImage(qImg));
}

void MainWindow::showImage_2(QImage qImg)
{
	ui->displaywindow_2->setPixmap(QPixmap::fromImage(qImg));
}

void MainWindow::on_actionPlay_triggered()
{
	ui->actionPlay->setDisabled(true);
	ui->actionSetImageRecordPath->setDisabled(false);
	ui->actionStop->setDisabled(false);
	ui->actionCalibrate->setDisabled(false);
	ui->parameter_tree->setEnabled(false);

    for (auto & item: image_control_ptr_vec)
    {
        if (item == nullptr) continue;
        item->Regist();
		item->is_playing = true;
    }
    for (auto item : image_control_ptr_vec)
    {
        if (item == nullptr) continue;
        item->Run_Acquire();
    }
}

void MainWindow::on_actionSetImageRecordPath_triggered()
{
    QString fileName = QFileDialog::getExistingDirectory(this, "Save Image Path");
    if (!fileName.isNull())
    {
		//创建目录
		std::string tmp_path = fileName.toStdString();
		tmp_path=std::regex_replace(tmp_path, std::regex("/"), std::string("\\"));
		images_savefolder = tmp_path;
    }
	ui->actionRecord->setDisabled(false);
}

void MainWindow::on_actionRecord_triggered()
{
	ui->actionPlay->setDisabled(true);
	ui->actionSetImageRecordPath->setDisabled(true);
	ui->actionRecord->setDisabled(true);
	ui->actionStop->setDisabled(false);
    for (int i=0;i<image_control_ptr_vec.size();i++)
    {
		if (image_control_ptr_vec[i] == nullptr) continue;
		//获取时间以创建不同相机的保存目录
		time_t t = time(0);
		char tmp_time[64];
		strftime(tmp_time, sizeof(tmp_time), "%Y%m%d%H%M", localtime(&t));
		std::string tmp_path = images_savefolder + "\\" + std::string(tmp_time) + "Camera" + std::to_string(i + 1);
		mkdir(tmp_path.c_str());

		image_control_ptr_vec[i]->m_FilePathToSave = tmp_path;
		image_control_ptr_vec[i]->picNr_toSave = 0;
    }
	for (int i = 0;i < image_control_ptr_vec.size();i++)
	{
		if (image_control_ptr_vec[i] == nullptr) continue;
		image_control_ptr_vec[i]->is_recording = true;
	}
}

void MainWindow::on_actionStop_triggered()
{
	ui->actionPlay->setDisabled(false);
	ui->actionSetImageRecordPath->setDisabled(true);
	ui->actionRecord->setDisabled(true);
	ui->actionStop->setDisabled(true);
	ui->parameter_tree->setEnabled(true);
	ui->actionCalibrate->setDisabled(true);
	ui->actionSetCalibrationPath->setEnabled(false);
	ui->actionCalib_capture->setEnabled(false);

    for (auto item : image_control_ptr_vec)
    {
        if (item == nullptr) continue;
        item->is_recording = false;
		item->is_playing = false;
        item->Stop_Acquire();
    }

	if (calibrator_ptr != nullptr)
	{
		delete calibrator_ptr;
		calibrator_ptr = nullptr;
	}
}

void MainWindow::on_actionCalibrate_triggered()
{
	ui->actionSetCalibrationPath->setEnabled(true);
	CaliParaSetDialog* caliparasetdialog = new CaliParaSetDialog;
	qRegisterMetaType<CaliParameter>("CaliParameter");
	connect(caliparasetdialog, SIGNAL(sendCaliParameter(CaliParameter)), this, SLOT(receiveCaliParameter(CaliParameter)));
	caliparasetdialog->show();
}

void MainWindow::receiveCaliParameter(CaliParameter cali_para)
{
	this->calibrate_para = cali_para;
	if (this->calibrator_ptr != nullptr) delete calibrator_ptr;
	if (image_control_ptr_vec[0] && image_control_ptr_vec[1])
	{
		auto cam_para = image_control_ptr_vec[0]->GetCameraParameter();
		this->calibrator_ptr = new CameraCalibrateControler(
			true,
			true,
			atoi(cam_para.m_ImageWidth.c_str()),
			atoi(cam_para.m_ImageHeight.c_str()),
			calibrate_para.CornerAmountAlongWidth,
			calibrate_para.CornerAmountAlongHeight,
			calibrate_para.DistanceBetweenCorners,
			calibrate_para.PictureAmount,
			(CalibrationBoardType)calibrate_para.CalibrationBoardType);
		connect(image_control_ptr_vec[0], SIGNAL(sendCalibImage(void *)), this->calibrator_ptr, SLOT(recieveLeftImage(void *)));
		connect(image_control_ptr_vec[1], SIGNAL(sendCalibImage(void *)), this->calibrator_ptr, SLOT(recieveRightImage(void *)));
		connect(calibrator_ptr, SIGNAL(SignalCalibrate()), this, SLOT(CalibAndShow()));
	}
	else if (image_control_ptr_vec[0])
	{
		auto cam_para = image_control_ptr_vec[0]->GetCameraParameter();
		this->calibrator_ptr = new CameraCalibrateControler(
			true,
			false,
			atoi(cam_para.m_ImageWidth.c_str()),
			atoi(cam_para.m_ImageHeight.c_str()),
			calibrate_para.CornerAmountAlongWidth,
			calibrate_para.CornerAmountAlongHeight,
			calibrate_para.DistanceBetweenCorners,
			calibrate_para.PictureAmount,
			(CalibrationBoardType)calibrate_para.CalibrationBoardType);
		connect(image_control_ptr_vec[0], SIGNAL(sendCalibImage(void*)), calibrator_ptr, SLOT(recieveLeftImage(void *)));
		connect(calibrator_ptr, SIGNAL(SignalCalibrate()), this, SLOT(CalibAndShow()));
	}
	else if(image_control_ptr_vec[1])
	{
		auto cam_para = image_control_ptr_vec[1]->GetCameraParameter();
		this->calibrator_ptr = new CameraCalibrateControler(
			false,
			true,
			atoi(cam_para.m_ImageWidth.c_str()),
			atoi(cam_para.m_ImageHeight.c_str()),
			calibrate_para.CornerAmountAlongWidth,
			calibrate_para.CornerAmountAlongHeight,
			calibrate_para.DistanceBetweenCorners,
			calibrate_para.PictureAmount,
			(CalibrationBoardType)calibrate_para.CalibrationBoardType);
		connect(image_control_ptr_vec[1], SIGNAL(sendCalibImage(void *)), this->calibrator_ptr, SLOT(recieveRightImage(void *)));
		connect(calibrator_ptr, SIGNAL(SignalCalibrate()), this, SLOT(CalibAndShow()));
	}
}

void MainWindow::on_actionSetCalibrationPath_triggered()
{
    QString fileName = QFileDialog::getExistingDirectory(this, "Save Calibration Path");

    if (!fileName.isNull())
    {
		//创建目录
		std::string tmp_path = fileName.toStdString();
		tmp_path = std::regex_replace(tmp_path, std::regex("/"), std::string("\\"));
		calibrate_savefolder = tmp_path;

		ui->actionCalib_capture->setEnabled(true);
		ui->actionCalibrate->setDisabled(true);
    }
}

void MainWindow::on_actionCalib_capture_triggered()
{
	calibrator_ptr->collect_img_count = 0;
	//先停
	for (auto item : image_control_ptr_vec)
	{
		if (item == nullptr) continue;
		item->Stop_Acquire();
		item->is_playing = false;
		item->is_recording = false;
		item->is_calibrating = false;
	}
	//采一张
	for (auto & item : image_control_ptr_vec)
	{
		if (item == nullptr) continue;
		item->Regist();
		item->is_calibrating = true;
	}
	for (auto item : image_control_ptr_vec)
	{
		if (item == nullptr) continue;
		item->Run_Acquire(1);
	}
}

void MainWindow::CalibAndShow()
{
	//显示标定对话框
	CalibDialog* calibdialog = new CalibDialog;
	for (size_t i = 0; i < image_control_ptr_vec.size(); i++)
	{
		if (image_control_ptr_vec[i])
		{
			if (i == 0)
			{
				connect(calibrator_ptr, SIGNAL(sendLeftCalibImage(QImage)), calibdialog, SLOT(showCalibImage_1(QImage)));
			}
			else
			{
				connect(calibrator_ptr, SIGNAL(sendRightCalibImage(QImage)), calibdialog, SLOT(showCalibImage_2(QImage)));
			}
		}
	}
	connect(calibrator_ptr, SIGNAL(sendCalibrateStatus(QVector<QString>)), calibdialog, SLOT(showCalibStatus(QVector<QString>)));
	calibdialog->show();
	//标定,转QImg,emit
	cv::Mat cvLeftImg, cvRightImg;
	QImage qLeftImg, qRightImg;
	Gray8bitQImageCorlorTable cvt;
	int res;
	if (image_control_ptr_vec[0] != nullptr && image_control_ptr_vec[1] != nullptr)
	{
		res = calibrator_ptr->Calibrate(calibrator_ptr->left_img_ptr, cvLeftImg, calibrator_ptr->right_img_ptr, cvRightImg);
		if (res >= 0)
		{
			qLeftImg = QImage(cvLeftImg.data, calibrator_ptr->m_img_width, calibrator_ptr->m_img_height, QImage::Format_RGB888);
			qRightImg = QImage(cvRightImg.data, calibrator_ptr->m_img_width, calibrator_ptr->m_img_height, QImage::Format_RGB888);
			qLeftImg.setColorTable(cvt.GetGray8bitQImageCorlorTable());
			qRightImg.setColorTable(cvt.GetGray8bitQImageCorlorTable());

			emit calibrator_ptr->sendLeftCalibImage(qLeftImg);
			emit calibrator_ptr->sendRightCalibImage(qRightImg);
			emit calibrator_ptr->sendCalibrateStatus(QVector<QString>{
				"ValidImage",
					"ValidImage",
					QString::fromStdString(std::to_string(this->calibrate_para.PictureAmount - res) + "/" + std::to_string(this->calibrate_para.PictureAmount))});
		}
		else
		{
			emit calibrator_ptr->sendCalibrateStatus(QVector<QString>{
				"INValidImage",
					"INValidImage",
					QString::fromStdString(std::to_string(res) + "/" + std::to_string(this->calibrate_para.PictureAmount))});
		}
	}
	else if (image_control_ptr_vec[0] != nullptr && image_control_ptr_vec[1] == nullptr)
	{
		res = calibrator_ptr->Calibrate(calibrator_ptr->left_img_ptr, cvLeftImg, nullptr, cvRightImg);
		if (res >= 0)
		{
			qLeftImg = QImage(cvLeftImg.data, calibrator_ptr->m_img_width, calibrator_ptr->m_img_height, QImage::Format_RGB888);
			qLeftImg.setColorTable(cvt.GetGray8bitQImageCorlorTable());

			emit calibrator_ptr->sendLeftCalibImage(qLeftImg);
			emit calibrator_ptr->sendCalibrateStatus(QVector<QString>{
				"ValidImage",
					"NoCamera",
					QString::fromStdString(std::to_string(this->calibrate_para.PictureAmount - res) + "/" + std::to_string(this->calibrate_para.PictureAmount))});
		}
		else
		{
			emit calibrator_ptr->sendCalibrateStatus(QVector<QString>{
				"INValidImage",
					"NoCamera",
					QString::fromStdString(std::to_string(res) + "/" + std::to_string(this->calibrate_para.PictureAmount))});

		}
	}
	else if (image_control_ptr_vec[0] == nullptr && image_control_ptr_vec[1] != nullptr)
	{
		res = calibrator_ptr->Calibrate(nullptr, cvLeftImg, calibrator_ptr->right_img_ptr, cvRightImg);
		if (res >= 0)
		{
			qRightImg = QImage(cvRightImg.data, calibrator_ptr->m_img_width, calibrator_ptr->m_img_height, QImage::Format_RGB888);
			qRightImg.setColorTable(cvt.GetGray8bitQImageCorlorTable());

			emit calibrator_ptr->sendRightCalibImage(qRightImg);
			emit calibrator_ptr->sendCalibrateStatus(QVector<QString>{
				"NoCamera",
					"ValidImage",
					QString::fromStdString(std::to_string(this->calibrate_para.PictureAmount - res) + "/" + std::to_string(this->calibrate_para.PictureAmount))});
		}
		else
		{
			emit calibrator_ptr->sendCalibrateStatus(QVector<QString>{
				"NoCamera",
					"INValidImage",
					QString::fromStdString(std::to_string(res) + "/" + std::to_string(this->calibrate_para.PictureAmount))});
		}
	}
	//若标定完，显示结果并保存
	if (0 == res)
	{
		CameraCalibrateResult calib_result = calibrator_ptr->GetCalibrateResult();
		time_t t = time(0);
		char tmp_time[64];
		strftime(tmp_time, sizeof(tmp_time), "%Y%m%d%H%M", localtime(&t));
		std::string tmp_path = calibrate_savefolder + "\\" + std::string(tmp_time) + "CameraCalibrateResult.txt";
		std::ofstream outfile(tmp_path.c_str());

		size_t cnt = 0;
		for (size_t i = 0; i < image_control_ptr_vec.size(); i++)
		{
			if (image_control_ptr_vec[i])
			{
				if (0 == i)
				{
					outfile << "The LEFT camera calibrate result:\n";
					outfile << "Camera Matrix:\n";
					outfile << calib_result.m_LeftCalibrateResult.m_CameraMatrix << '\n';
					outfile << "Camera DistCoeffs:\n";
					outfile << calib_result.m_LeftCalibrateResult.m_DistCoeffs << '\n';
				}
				else
				{
					outfile << "The RIGHT camera calibrate result:\n";
					outfile << "Camera Matrix:\n";
					outfile << calib_result.m_RightCalibrateResult.m_CameraMatrix << '\n';
					outfile << "Camera DistCoeffs:\n";
					outfile << calib_result.m_RightCalibrateResult.m_DistCoeffs << '\n';
				}
				cnt++;
			}
		}
		if (2 == cnt)
		{
			outfile << "Rotate Matrix\n" << calib_result.R << '\n';
			outfile << "Transverse Matrix\n" << calib_result.T << '\n';
			outfile << "Total Err\n" << calib_result.m_RMS_error << '\n';
		}
		outfile.close();
	}
	//stop
	for (auto item : image_control_ptr_vec)
	{
		if (item == nullptr) continue;
		item->is_calibrating = false;
		item->Stop_Acquire();
	}
	//continue to play
	for (auto & item : image_control_ptr_vec)
	{
		if (item == nullptr) continue;
		item->Regist();
		item->is_playing = true;
	}
	for (auto item : image_control_ptr_vec)
	{
		if (item == nullptr) continue;
		item->Run_Acquire();
	}
}