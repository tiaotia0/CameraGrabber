#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    display_window = {ui->display_1, ui->display_2};
    connect(ui->parameter_1,SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(openEditor_1(QTreeWidgetItem*, int)));
    connect(ui->parameter_1,SIGNAL(itemSelectionChanged()), this, SLOT(closeEditor_1()));
	connect(ui->parameter_2, SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this, SLOT(openEditor_2(QTreeWidgetItem*, int)));
	connect(ui->parameter_2, SIGNAL(itemSelectionChanged()), this, SLOT(closeEditor_2()));

    ui->parameter_1->setStyleSheet("QTreeWidget::item{height:25px}");
    ui->parameter_2->setStyleSheet("QTreeWidget::item{height:25px}");

	isloaded = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_clicked()
{
	if (isloaded == true)
	{
		for (auto item : v)
		{
			if (item == nullptr) continue;
			item->Stop_Acquire();
		}
		delete imagedisplay;
		v.resize(0);
	}
	sysboards.InitialSystemImageCaptureBoards();
	global_board_ptr = &(*sysboards.m_VecOfImageCaptureBoard.begin());
    global_board_ptr->RefreshPortConnectStatus();
    for (size_t i = 0; i < global_board_ptr->m_PortAmount; i++)
    {
        if (!global_board_ptr->m_CameraConnectStatus[i]) continue;
        status[i]->setText("Connected");
		set_vec[i]->setEnabled(true);
		parameterTree[i]->setEnabled(true);
        para = global_board_ptr->GetCameraParameter(i);
        showParameters(i);
    }

    for (size_t i = 0; i < global_board_ptr->m_CameraConnectStatus.size(); i++)
    {
        if (global_board_ptr->m_CameraConnectStatus[i])
        {
            imagedisplay = new ImageDisplayControler(*global_board_ptr, i);
            v.push_back(imagedisplay);
            if (i == 0)
                connect(imagedisplay, SIGNAL(sendImage(QImage)), this, SLOT(showImage_1(QImage)));
            else
                connect(imagedisplay, SIGNAL(sendImage(QImage)), this, SLOT(showImage_2(QImage)));
            v[i]->Regist();
        }
        else
            v.push_back(nullptr);
    }
	isloaded = true;
}

void MainWindow::showParameters(size_t i)
{
    para = global_board_ptr->GetCameraParameter(i);
    parameterTree[i]->topLevelItem(0)->setText(1, QString::fromStdString(para.m_ImageWidth));
    parameterTree[i]->topLevelItem(1)->setText(1, QString::fromStdString(para.m_ImageHeight));
    parameterTree[i]->topLevelItem(2)->setText(1, QString::fromStdString(para.m_ImageRate));
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

    for (size_t i = 0; i < global_board_ptr->m_CameraConnectStatus.size(); i++)
    {
		if (!global_board_ptr->m_CameraConnectStatus[i]) continue;
		global_board_ptr->command_SetFrameFormat(i, width.toInt(), height.toInt());
        global_board_ptr->command_SetFrameRate(i, frameRate.toInt());
        global_board_ptr->command_SetExposure(i, exposure.toInt());
        if (synchro == "Intern")
            global_board_ptr->command_SetInternSynchro(i);
        else if (synchro == "Extern")
            global_board_ptr->command_SetExternSynchro(i);
        if (polarity == "Positive edge")
            global_board_ptr->command_SetPositiveEdge(i);
        else if (polarity == "Positive level")
            global_board_ptr->command_SetPositiveLevel(i);
        else if (polarity == "Negative edge")
            global_board_ptr->command_SetNegativeEdge(i);
        else if (polarity == "Negative level")
            global_board_ptr->command_SetNegativeLevel(i);

        if (clmode == "2×8 bits")
            global_board_ptr->command_SetBase_2_8_bits(i);
        else if (clmode == "2×10 bits")
            global_board_ptr->command_SetBase_2_10_bits(i);

        if (clfrequency == "66MHz")
            global_board_ptr->command_SetCameraLinkFrequency(1, 0);
        else if (clfrequency == "75MHz")
            global_board_ptr->command_SetCameraLinkFrequency(1, 1);
        else if (clfrequency == "85MHz")
            global_board_ptr->command_SetCameraLinkFrequency(1, 2);

        para = global_board_ptr->GetCameraParameter(i);
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

void MainWindow::showImage_1(QImage qImg)
{
    ui->display_1->setPixmap(QPixmap::fromImage(qImg));
}

void MainWindow::showImage_2(QImage qImg)
{
    ui->display_2->setPixmap(QPixmap::fromImage(qImg));
}

void MainWindow::on_start_clicked()
{
    for (auto item : v)
    {
        if (item == nullptr) continue;
        item->Run_Acquire();
    }
}

void MainWindow::on_stop_clicked()
{
    for (auto item : v)
    {
        if (item == nullptr) continue;
        item->Stop_Acquire();
    }
}

void MainWindow::on_pause_clicked()
{
    for (auto item : v)
    {
        if (item == nullptr) continue;
        item->Pause_Acquire();
    }
}

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

