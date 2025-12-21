#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customerdialog.h"
#include "sellerdialog.h"
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setupListWindows();
}

MainWindow::~MainWindow() {
    delete ui;
    qDeleteAll(customers);
    qDeleteAll(sellers);
}

void MainWindow::setupListWindows() {
    customerListWindow = new QDialog(this);
    customerListWindow->setWindowTitle("Customer List");
    QVBoxLayout *l1 = new QVBoxLayout(customerListWindow);
    customerListWidget = new QListWidget(customerListWindow);
    l1->addWidget(customerListWidget);
    customerListWindow->resize(600, 400);

    sellerListWindow = new QDialog(this);
    sellerListWindow->setWindowTitle("Seller List");
    QVBoxLayout *l2 = new QVBoxLayout(sellerListWindow);
    sellerListWidget = new QListWidget(sellerListWindow);
    l2->addWidget(sellerListWidget);
    sellerListWindow->resize(600, 400);
}

void MainWindow::on_btnCreateCustomer_clicked() {
    CustomerDialog *dlg = new CustomerDialog(this);
    connect(dlg, &CustomerDialog::customerCreated, this, &MainWindow::addCustomer);
    dlg->exec();
    delete dlg;
}

void MainWindow::addCustomer(Customer* c) {
    for(Customer* existing : std::as_const(customers)) {
        if (*existing == *c) {
            QMessageBox::warning(this, "Error", "Duplicate Customer!");
            return;
        }
    }
    customers.append(c);
    customerListWidget->addItem(c->getInfo());
}

void MainWindow::on_btnCreateSeller_clicked() {
    SellerDialog *dlg = new SellerDialog(this);
    connect(dlg, &SellerDialog::sellerCreated, this, &MainWindow::addSeller);
    dlg->exec();
    delete dlg;
}

void MainWindow::addSeller(Seller* s) {
    for(Seller* existing : std::as_const(sellers)) {
        if (*existing == *s) {
            QMessageBox::warning(this, "Error", "Duplicate Seller!");
            return;
        }
    }
    sellers.append(s);
    sellerListWidget->addItem(s->getInfo());
}

void MainWindow::on_btnShowCustomerList_clicked() {
    if(customerListWindow->isVisible())
        customerListWindow->hide();
    else
        customerListWindow->show();
}

void MainWindow::on_btnShowSellerList_clicked() {
    if(sellerListWindow->isVisible())
        sellerListWindow->hide();
    else
        sellerListWindow->show();
}

void MainWindow::on_btnExit_clicked() {
    QApplication::exit();
}
