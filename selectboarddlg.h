#ifndef SELECTBOARDDLG_H
#define SELECTBOARDDLG_H

#include <QDialog>

namespace Ui {
class selectboarddlg;
}

class selectboarddlg : public QDialog
{
    Q_OBJECT

public:
    explicit selectboarddlg(QWidget *parent = 0);
    ~selectboarddlg();

private:
    Ui::selectboarddlg *ui;
};

#endif // SELECTBOARDDLG_H
