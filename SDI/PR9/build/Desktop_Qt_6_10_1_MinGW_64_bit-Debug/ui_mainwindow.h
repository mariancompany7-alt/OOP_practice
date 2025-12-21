/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *leID;
    QLineEdit *leBalance;
    QLineEdit *leAddress;
    QPushButton *pbExit;
    QLineEdit *lePatronymic;
    QPushButton *pbCreate;
    QLineEdit *leCardNumber;
    QLineEdit *leFirstname;
    QLineEdit *leLastname;
    QPushButton *pbOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        leID = new QLineEdit(groupBox);
        leID->setObjectName("leID");

        gridLayout->addWidget(leID, 0, 1, 1, 1);

        leBalance = new QLineEdit(groupBox);
        leBalance->setObjectName("leBalance");

        gridLayout->addWidget(leBalance, 2, 0, 1, 1);

        leAddress = new QLineEdit(groupBox);
        leAddress->setObjectName("leAddress");

        gridLayout->addWidget(leAddress, 0, 0, 1, 1);

        pbExit = new QPushButton(groupBox);
        pbExit->setObjectName("pbExit");

        gridLayout->addWidget(pbExit, 4, 1, 1, 1);

        lePatronymic = new QLineEdit(groupBox);
        lePatronymic->setObjectName("lePatronymic");

        gridLayout->addWidget(lePatronymic, 3, 1, 1, 1);

        pbCreate = new QPushButton(groupBox);
        pbCreate->setObjectName("pbCreate");

        gridLayout->addWidget(pbCreate, 3, 0, 1, 1);

        leCardNumber = new QLineEdit(groupBox);
        leCardNumber->setObjectName("leCardNumber");

        gridLayout->addWidget(leCardNumber, 1, 0, 1, 1);

        leFirstname = new QLineEdit(groupBox);
        leFirstname->setObjectName("leFirstname");

        gridLayout->addWidget(leFirstname, 2, 1, 1, 1);

        leLastname = new QLineEdit(groupBox);
        leLastname->setObjectName("leLastname");

        gridLayout->addWidget(leLastname, 1, 1, 1, 1);

        pbOutput = new QPushButton(groupBox);
        pbOutput->setObjectName("pbOutput");

        gridLayout->addWidget(pbOutput, 4, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        leID->setPlaceholderText(QCoreApplication::translate("MainWindow", "id", nullptr));
        leBalance->setPlaceholderText(QCoreApplication::translate("MainWindow", "balance", nullptr));
        leAddress->setPlaceholderText(QCoreApplication::translate("MainWindow", "address", nullptr));
        pbExit->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\271\321\202\320\270", nullptr));
        lePatronymic->setPlaceholderText(QCoreApplication::translate("MainWindow", "patronymic", nullptr));
        pbCreate->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\262\320\276\321\200\320\270\321\202\320\270 \320\276\320\261'\321\224\320\272\321\202", nullptr));
        leCardNumber->setPlaceholderText(QCoreApplication::translate("MainWindow", "Number of card", nullptr));
        leFirstname->setPlaceholderText(QCoreApplication::translate("MainWindow", "firstname", nullptr));
        leLastname->setPlaceholderText(QCoreApplication::translate("MainWindow", "lastname", nullptr));
        pbOutput->setText(QCoreApplication::translate("MainWindow", "\320\222\321\226\320\264\320\276\320\261\321\200\320\260\320\267\320\270\321\202\320\270 \320\276\320\261'\321\224\320\272\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
