#ifndef SELLER_H
#define SELLER_H

#include "person.h"

class Seller : public Person {
    long accountNumber;
    QString productList;

public:
    Seller();
    Seller(int id, QString lastName, QString firstName, QString midName, QString addr, long acc, QString products);

    QString getInfo() const override;

    long getAccountNumber() const { return accountNumber; }
    QString getProductList() const { return productList; }

    friend istream& operator >> (istream& is, Seller& s);
    friend ostream& operator << (ostream& os, const Seller& s);
    friend bool operator == (const Seller& s1, const Seller& s2);
};

#endif // SELLER_H
