#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QDialog>
#include <QList>
#include "customer.h"
#include "seller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCreateCustomer_clicked();
    void on_btnCreateSeller_clicked();
    void on_btnShowCustomerList_clicked();
    void on_btnShowSellerList_clicked();
    void on_btnExit_clicked();

    void addCustomer(Customer* c);
    void addSeller(Seller* s);

private:
    Ui::MainWindow *ui;

    QList<Customer*> customers;
    QList<Seller*> sellers;

    QDialog *customerListWindow;
    QListWidget *customerListWidget;

    QDialog *sellerListWindow;
    QListWidget *sellerListWidget;

    void setupListWindows();
};

#endif // MAINWINDOW_H
