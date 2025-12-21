#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "customer.h"
#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pbCreate_clicked();

    void on_pbOutput_clicked();

    void on_pbExit_clicked();

private:
    Ui::MainWindow *ui;
    Customer* c;
};
#endif // MAINWINDOW_H
