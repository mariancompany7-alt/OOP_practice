#include "qsqldbmanager.h"

QsqlDBManager::QsqlDBManager() {

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./PR11.db");
}

void QsqlDBManager::connectToDataBase() {

    if (!db.open()) {
        qDebug("Database connection failed");
        throw std::runtime_error("Неможливо відкрити файл бази даних!");
    } else {
        qDebug() << "Connected to the database!";
    }
}

void QsqlDBManager::closeDataBase() {

    if (db.isOpen()) {
    db.close();
    }
}

QSqlDatabase QsqlDBManager::getDB() { return db; }

bool QsqlDBManager::createTables() {

    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS customers (id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "lastname TEXT NOT NULL, firstname TEXT NOT NULL,"
                  "patronymic TEXT NOT NULL, address TEXT NOT NULL,"
                  "creditCardNumber INT NOT NULL, balance INT NOT NULL)");

    if (!query.exec()) {
        qDebug() << "Table customers creation failed";
        return false;
    } else {
        qDebug() << "Table customers creation successfully!";
    }

    query.prepare("CREATE TABLE IF NOT EXISTS sellers (id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "lastname TEXT NOT NULL, firstname TEXT NOT NULL,"
                  "patronymic TEXT NOT NULL, address TEXT NOT NULL,"
                  "accountNumber INT NOT NULL, productList TEXT NOT NULL)");

    if (!query.exec()) {
        qDebug() << "Table sellers creating failed";
        return false;
    } else {
        qDebug() << "Table sellers creating successfully!";
    }
    return true;
}

bool QsqlDBManager::insertIntoTable(const Customer& c) {

    QSqlQuery query;
    query.prepare("INSERT INTO customers (id, lastname, firstname, patronymic, address, "
                  "creditCardNumber, balance) VALUES (:id, :lastname, :firstname, :patronymic,"
                  ":address, :creditCardNumber, :balance)");
    query.bindValue(":id", c.getId());
    query.bindValue(":lastname", c.getLastName());
    query.bindValue(":firstname", c.getFirstName());
    query.bindValue(":patronymic", c.getPatronymic());
    query.bindValue(":address", c.getAddress());
    query.bindValue(":creditCardNumber", static_cast<qlonglong>(c.getCardNumber()));
    query.bindValue(":balance", c.getBalance());

    if (!query.exec()) {
        qDebug() << "Insertion into customer table failed";
    } else {
        qDebug() << "Insertion into customer table successfully!";
        return false;
    }
    return true;
}

bool QsqlDBManager::insertIntoTable(const Seller& s) {

    QSqlQuery query;
    query.prepare("INSERT INTO sellers (id, lastname, firstname, patronymic, address, "
                  "accountNumber, productList) "
                  "VALUES (:id, :lastname, :firstname, :patronymic, "
                  ":address, :accountNumber, :productList)");

    query.bindValue(":id", s.getId());
    query.bindValue(":lastname", s.getLastName());
    query.bindValue(":firstname", s.getFirstName());
    query.bindValue(":patronymic", s.getPatronymic());
    query.bindValue(":address", s.getAddress());

    query.bindValue(":accountNumber", (qlonglong)s.getAccountNumber());
    query.bindValue(":productList", s.getProductList());

    if (!query.exec()) {
        qDebug() << "Insertion into sellers table failed:";
        return false;
    } else {
        qDebug() << "Insertion into sellers table successfully!";
        return true;
    }
}
