#include "sellerdialog.h"
#include "ui_sellerdialog.h"
#include <QMessageBox>

SellerDialog::SellerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SellerDialog)
{
    ui->setupUi(this);
}

SellerDialog::~SellerDialog()
{
    delete ui;
}

void SellerDialog::on_btnCreate_clicked()
{
    if(ui->leLastname->text().isEmpty() || ui->leAccountNumber->text().isEmpty()) {
        QMessageBox::warning(this, "Помилка", "Заповніть обов'язкові поля!");
        return;
    }

    Seller *s = new Seller(
        ui->leID->text().toInt(),
        ui->leLastname->text(),
        ui->leFirstname->text(),
        ui->lePatronymic->text(),
        ui->leAddress->text(),
        ui->leAccountNumber->text().toLong(),
        ui->leList->text()
        );

    emit sellerCreated(s);
    accept();
}
