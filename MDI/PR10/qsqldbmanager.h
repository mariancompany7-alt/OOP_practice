#ifndef QSQLDBMANAGER_H
#define QSQLDBMANAGER_H

#include<QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "customer.h"
#include "seller.h"

class QsqlDBManager
{
public:
    QsqlDBManager();

    void connectToDataBase();

    void closeDataBase();

    QSqlDatabase getDB();

    bool createTables();

    bool insertIntoTable(const Customer& c);

    bool insertIntoTable(const Seller& s);

private:

    QSqlDatabase db;
};

#endif // QSQLDBMANAGER_H
