#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"

class Customer : public Person {
    long creditCardNumber;
    double balance;

public:
    Customer();
    Customer(int id, QString lastName, QString firstName, QString midName, QString addr, long card, double bal);

    QString getInfo() const override;

    friend istream& operator >> (istream& is, Customer& c);
    friend ostream& operator << (ostream& os, const Customer& c);
    friend bool operator == (const Customer& c1, const Customer& c2);
};

#endif // CUSTOMER_H
