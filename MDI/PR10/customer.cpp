#include "customer.h"

Customer::Customer() : Person(), creditCardNumber(0), balance(0) {}

Customer::Customer(int id, QString lastName, QString firstName, QString midName, QString addr, long card, double bal)
    : Person(id, lastName, firstName, midName, addr), creditCardNumber(card), balance(bal) {}

QString Customer::getInfo() const {
    return QString("Customer id: %1 lastname: %2 firstname: %3 patronymic: %4 address: %5 card number: %6, balance: %7")
    .arg(id).arg(lastName).arg(firstName).arg(patronymic).arg(address).arg(creditCardNumber).arg(balance);
}

bool operator == (const Customer& c1, const Customer& c2) {
    return static_cast<const Person&>(c1) == static_cast<const Person&>(c2) &&
           c1.creditCardNumber == c2.creditCardNumber;
}

ostream& operator << (ostream& os, const Customer& c) {
    os << static_cast<const Person&>(c);
    os << " " << c.creditCardNumber << " " << c.balance;
    return os;
}

istream& operator >> (istream& is, Customer& c) {
    is >> static_cast<Person&>(c);
    is >> c.creditCardNumber >> c.balance;
    return is;
}
