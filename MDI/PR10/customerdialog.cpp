#include "customerdialog.h"
#include "ui_customerdialog.h"
#include <QMessageBox>

CustomerDialog::CustomerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomerDialog)
{
    ui->setupUi(this);
    setWindowTitle("Модальне вікно");
    setModal(true);
}

CustomerDialog::~CustomerDialog()
{
    delete ui;
}

void CustomerDialog::on_pbCreate_clicked()
{
    if (ui->leID->text().isEmpty() || ui->leLastname->text().isEmpty() || ui->leFirstname->text().isEmpty()
        || ui->lePatronymic->text().isEmpty() || ui->leAddress->text().isEmpty() || ui->leCardNumber->text().isEmpty()
        || ui->leBalance->text().isEmpty()) {

        QMessageBox::warning(this, "Помилка", "Заповніть усі поля!");
    }

    Customer* c = new Customer(ui->leID->text().toInt(),
                               ui->leLastname->text(),
                               ui->leFirstname->text(),
                               ui->lePatronymic->text(),
                               ui->leAddress->text(),
                               ui->leCardNumber->text().toLong(),
                               ui->leBalance->text().toDouble());

    emit customerCreated(c);
    this->accept();
}
