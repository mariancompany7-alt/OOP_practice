#ifndef CUSTOMERDIALOG_H
#define CUSTOMERDIALOG_H

#include "customer.h"
#include <QDialog>

namespace Ui {
class CustomerDialog;
}

class CustomerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerDialog(QWidget *parent = nullptr);
    ~CustomerDialog();

signals:
    void customerCreated(Customer* c);

private slots:
    void on_pbCreate_clicked();

private:
    Ui::CustomerDialog *ui;
};

#endif // CUSTOMERDIALOG_H
