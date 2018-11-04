#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_displaywindow.h"
//#include "calibrationdialog.h"

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

	parameterTree = { ui->parameter_1, ui->parameter_2 };
	synchro_vec = { this->synchro_box_1, this->synchro_box_2 };
	polarity_vec = { this->polarity_box_1, this->polarity_box_2 };
	clmode_vec = { this->clmode_box_1, this->clmode_box_2 };
	clfrequency_vec = { this->clfrequency_box_1, this->clfrequency_box_2 };
	set_vec = { ui->set_1, ui->set_2 };
	status = { ui->status_1, ui->status_2 };

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

    connect(ui->parameter_1,SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(openEditor_1(QTreeWidgetItem*, int)));
    connect(ui->parameter_1,SIGNAL(itemSelectionChanged()), this, SLOT(closeEditor_1()));
	connect(ui->parameter_2, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(openEditor_2(QTreeWidgetItem*, int)));
	connect(ui->parameter_2, SIGNAL(itemSelectionChanged()), this, SLOT(closeEditor_2()));

    ui->parameter_1->setStyleSheet("QTreeWidget::item{height:25px}");
    ui->parameter_2->setStyleSheet("QTreeWidget::item{height:25px}");
}

MainWindow::~MainWindow()
{
	delete sysboards;
	sysboards = nullptr;
    delete ui;
}

void MainWindow::on_load_clicked()
{
	if (sysboards!=nullptr)
	{
		for (size_t i = 0; i < display_window_ptr_vec.size(); i++)
		{
			QObject::disconnect(display_window_ptr_vec[i], SLOT(freshWindow(QImage)));
		}
		for (auto &item : display_window_ptr_vec)
		{
			delete item;
		}
		for (auto &item : image_control_ptr_vec)
		{
			delete item;
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
			status[i]->setText("disConnected");
			set_vec[i]->setEnabled(false);
			parameterTree[i]->setEnabled(false);
			continue;
		}
        status[i]->setText("Connected");
		set_vec[i]->setEnabled(true);
		parameterTree[i]->setEnabled(true);
    }
	image_control_ptr_vec = std::vector<Base_ImageContrler*>(first_board_ptr->GetBoardPortAmount(), nullptr);
	display_window_ptr_vec = std::vector<DisplayWindow *>(first_board_ptr->GetBoardPortAmount(), nullptr);
	for (size_t i = 0; i < CameraConnectStatus.size(); i++)
	{
		if (CameraConnectStatus[i] && display_window_ptr_vec[i] == nullptr)
		{
			auto tmp_ptr = new DisplayWindow();
			display_window_ptr_vec[i] = tmp_ptr;
			if (i == 0)
			{
				ui->mdiArea_1->addSubWindow(tmp_ptr);
				tmp_ptr->show();
				ui->mdiArea_1->activeSubWindow();
			}
			else
			{
				ui->mdiArea_2->addSubWindow(tmp_ptr);
				tmp_ptr->show();
				ui->mdiArea_2->activeSubWindow();
			}
		}
	}
	for (size_t i = 0; i < CameraConnectStatus.size(); i++)
	{
		if (CameraConnectStatus[i] && image_control_ptr_vec[i] == nullptr)
		{
			auto tmp_ptr = new ImageDisplayControler(*first_board_ptr, i);
			image_control_ptr_vec[i] = tmp_ptr;
			connect(tmp_ptr, SIGNAL(sendImage(QImage)), display_window_ptr_vec[i], SLOT(freshWindow(QImage)));
			showParameters(i);
		}
	}
}

void MainWindow::showParameters(size_t i)
{
	Base_ImageContrler *img_ctrl_ptr = image_control_ptr_vec[i];
    auto para = img_ctrl_ptr->GetCameraParameter();
    parameterTree[i]->topLevelItem(0)->setText(1, QString::fromStdString(para.m_ImageWidth));
    parameterTree[i]->topLevelItem(1)->setText(1, QString::fromStdString(para.m_ImageHeight));
    parameterTree[i]->topLevelItem(2)->setText(1, QString::fromStdString(para.m_FrameFrequency));
    parameterTree[i]->topLevelItem(3)->setText(1, QString::fromStdString(para.m_ExposureTime));

    parameterTree[i]->setItemWidget(parameterTree[i]->topLevelItem(4), 1, synchro_vec[i]);
    parameterTree[i]->setItemWidget(parameterTree[i]->topLevelItem(5), 1, polarity_vec[i]);
    parameterTree[i]->setItemWidget(parameterTree[i]->topLevelItem(6), 1, clmode_vec[i]);
    parameterTree[i]->setItemWidget(parameterTree[i]->topLevelItem(7), 1, clfrequency_vec[i]);

    synchro_vec[i]->setCurrentText(QString::fromStdString(para.m_Synchro));
    polarity_vec[i]->setCurrentText(QString::fromStdString(para.m_Polarity));
    clmode_vec[i]->setCurrentText(QString::fromStdString(para.m_CLMode));
    clfrequency_vec[i]->setCurrentText(QString::fromStdString(para.m_CameraLinkFrequency));

    parameterTree[i]->topLevelItem(4)->setText(1, QString::fromStdString(para.m_Synchro));
    parameterTree[i]->topLevelItem(5)->setText(1, QString::fromStdString(para.m_Polarity));
    parameterTree[i]->topLevelItem(6)->setText(1, QString::fromStdString(para.m_CLMode));
    parameterTree[i]->topLevelItem(7)->setText(1, QString::fromStdString(para.m_CameraLinkFrequency));
}

void MainWindow::setParameters(size_t k)
{
	QString width = parameterTree[k]->topLevelItem(0)->text(1);
	QString height = parameterTree[k]->topLevelItem(1)->text(1);
	QString frameRate = parameterTree[k]->topLevelItem(2)->text(1);
	QString exposure = parameterTree[k]->topLevelItem(3)->text(1);
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

void MainWindow::on_play_clicked()
{
	//todo：开始之后变灰
	for (auto & item: image_control_ptr_vec)
	{
		if (item == nullptr) continue;
		item->Regist();
	}
	
    for (auto item : image_control_ptr_vec)
    {
        if (item == nullptr) continue;
        item->Run_Acquire();
    }
}

void MainWindow::on_record_clicked()
{
	for (auto &item : image_control_ptr_vec)
	{
		item->is_recording = true;
	}
}

void MainWindow::on_stop_clicked()
{
	//todo:未录制时为灰，录制后方可使用
    for (auto item : image_control_ptr_vec)
    {
		if (item == nullptr) continue;
		item->is_recording = false;
        item->Stop_Acquire();
    }
}

//void MainWindow::on_calibration_clicked()
//{
//	//显示标定对话框
//	CalibDialog* calibdialog = new CalibDialog;
//	calibdialog->exec();
//}

void MainWindow::openEditor_1(QTreeWidgetItem *item, int column)
{
    if (item == ui->parameter_1->topLevelItem(0) || item == ui->parameter_1->topLevelItem(1) || item == ui->parameter_1->topLevelItem(2) || item == ui->parameter_1->topLevelItem(3))
    {
        ui->parameter_1->openPersistentEditor(item, 1);
        temItem = item;
    }
}

void MainWindow::closeEditor_1()
{
    if (temItem == ui->parameter_1->topLevelItem(0) || temItem == ui->parameter_1->topLevelItem(1) || temItem == ui->parameter_1->topLevelItem(2) || temItem == ui->parameter_1->topLevelItem(3))
    {
        ui->parameter_1->closePersistentEditor(temItem, 1);
    }
}

void MainWindow::openEditor_2(QTreeWidgetItem *item, int column)
{
	if (item == ui->parameter_2->topLevelItem(0) || item == ui->parameter_2->topLevelItem(1) || item == ui->parameter_2->topLevelItem(2) || item == ui->parameter_2->topLevelItem(3))
	{
		ui->parameter_2->openPersistentEditor(item, 1);
		temItem = item;
	}
}

void MainWindow::closeEditor_2()
{
	if (temItem == ui->parameter_2->topLevelItem(0) || temItem == ui->parameter_2->topLevelItem(1) || temItem == ui->parameter_2->topLevelItem(2) || temItem == ui->parameter_2->topLevelItem(3))
	{
		ui->parameter_2->closePersistentEditor(temItem, 1);
	}
}

DisplayWindow::DisplayWindow(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DisplayWindow)
{
	ui->setupUi(this);
}

DisplayWindow::~DisplayWindow()
{
	delete ui;
}

void DisplayWindow::freshWindow(QImage img)
{
	ui->display_label->setPixmap(QPixmap::fromImage(img));
}
