#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    c = nullptr;
}

MainWindow::~MainWindow()
{
    if (c != nullptr) {
        delete c;
    }

    delete ui;
}

void MainWindow::on_pbCreate_clicked()
{
    // int id = ui->leID->text().toInt();
    QString lastname = ui->leLastname->text();
    QString fisrtname = ui->leFirstname->text();
    QString patronymic = ui->lePatronymic->text();
    QString address = ui->leAddress->text();
    // long cardNumber = ui->leCardNumber->text().toLong();
    // double balance = ui->leBalance->text().toDouble();

    if (lastname.isEmpty() || fisrtname.isEmpty() ||
        patronymic.isEmpty() || address.isEmpty()) {

        QMessageBox::warning(this, "Помилка", "Будь ласка, заповніть усі обов'язкові поля!");
        return;
    }

    if (c != nullptr) {
        delete c;
    }

    c = new Customer(ui->leID->text().toInt(), ui->leLastname->text(), ui->leFirstname->text(),
                     ui->lePatronymic->text(), ui->leAddress->text(), ui->leCardNumber->text().toLong(),
                     ui->leBalance->text().toDouble());

    QMessageBox::information(this, "Повідомлення", "Об'єкт успішно створено!");

}


void MainWindow::on_pbOutput_clicked()
{
    if (c == nullptr) {
        QMessageBox::warning(this, "Помилка", "Спершу створіть oб'єкт");
        return;
    }

    QMessageBox::information(this, "Пoвідомлення", c->toString());
}


void MainWindow::on_pbExit_clicked()
{
    QApplication::exit();
}

