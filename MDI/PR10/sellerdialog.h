#ifndef SELLERDIALOG_H
#define SELLERDIALOG_H

#include <QDialog>
#include "seller.h"

namespace Ui {
class SellerDialog;
}

class SellerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SellerDialog(QWidget *parent = nullptr);
    ~SellerDialog();

signals:
    void sellerCreated(Seller* newSeller);

private slots:
    void on_btnCreate_clicked();

private:
    Ui::SellerDialog *ui;
};

#endif // SELLERDIALOG_H
