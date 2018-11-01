#include "selectboarddlg.h"
#include "ui_selectboarddlg.h"

selectboarddlg::selectboarddlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectboarddlg)
{
    ui->setupUi(this);
}

selectboarddlg::~selectboarddlg()
{
    delete ui;
}
