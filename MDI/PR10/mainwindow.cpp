#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customerdialog.h"
#include "sellerdialog.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    dbManager = new QsqlDBManager();
    dbManager->connectToDataBase();
    dbManager->createTables();

    setupListWindows();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupListWindows() {

    customerListWindow = new QDialog(this);
    customerListWindow->setWindowTitle("Customer Database");
    QVBoxLayout *l1 = new QVBoxLayout(customerListWindow);

    customerModel = new QSqlTableModel(this, dbManager->getDB());
    customerModel->setTable("customers");
    customerModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    customerModel->select();

    customerTableView = new QTableView(customerListWindow);
    customerTableView->setModel(customerModel);
    customerTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    customerTableView->resizeColumnsToContents();

    l1->addWidget(customerTableView);
    customerListWindow->resize(600, 400);

    sellerListWindow = new QDialog(this);
    sellerListWindow->setWindowTitle("Seller Database");
    QVBoxLayout *l2 = new QVBoxLayout(sellerListWindow);

    sellerModel = new QSqlTableModel(this, dbManager->getDB());
    sellerModel->setTable("sellers");
    sellerModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    sellerModel->select();

    sellerTableView = new QTableView(sellerListWindow);
    sellerTableView->setModel(sellerModel);
    sellerTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    sellerTableView->resizeColumnsToContents();

    l2->addWidget(sellerTableView);
    sellerListWindow->resize(600, 400);
}

void MainWindow::on_btnCreateCustomer_clicked() {
    CustomerDialog *dlg = new CustomerDialog(this);
    connect(dlg, &CustomerDialog::customerCreated, this, &MainWindow::addCustomer);
    dlg->exec();
    delete dlg;
}

void MainWindow::addCustomer(Customer* c) {
    try {
    if (dbManager->insertIntoTable(*c)) {
        customerModel->select();
        QMessageBox::information(this, "Успіх", "Customer успішно додано до БД");
    }
        }

    catch (const std::exception& e) {
        qCritical() << "Exception caught:" << e.what();
        QMessageBox::critical(this, "Помилка", e.what());
    }
    catch (const std::exception) {
        qFatal("Unknown error occurred in addCustomer!");
    }
    delete c;

}

void MainWindow::on_btnCreateSeller_clicked() {
    SellerDialog *dlg = new SellerDialog(this);
    connect(dlg, &SellerDialog::sellerCreated, this, &MainWindow::addSeller);
    dlg->exec();
    delete dlg;
}

void MainWindow::addSeller(Seller* s) {

    if (dbManager->insertIntoTable(*s)) {
        sellerModel->select();
        QMessageBox::information(this, "Успіх", "Seller успішно додано до БД");
    } else {
        QMessageBox::warning(this, "Помилка", "Seller не додано до БД");
    }

    delete s;
}

void MainWindow::on_btnShowCustomerList_clicked() {

    if(customerListWindow->isVisible()) {
        customerListWindow->hide();
    } else {
        customerModel->select();
        customerListWindow->show();
    }
}

void MainWindow::on_btnShowSellerList_clicked() {

    if(sellerListWindow->isVisible()) {
        sellerListWindow->hide();
    } else {
        sellerModel->select();
        sellerListWindow->show();
    }
}

void MainWindow::on_btnExit_clicked() {
    QApplication::exit();
}
