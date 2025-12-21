#include "seller.h"

Seller::Seller() : Person(), accountNumber(0) {}

Seller::Seller(int id, QString lastName, QString firstName, QString midName, QString addr, long acc, QString products)
    : Person(id, lastName, firstName, midName, addr), accountNumber(acc), productList(products) {}

QString Seller::getInfo() const {
    return QString("Seller id: %1 lastname: %2 firstname: %3 patronymic: %4 address: %5, accound number: %6, products: %7")
    .arg(id).arg(lastName).arg(firstName).arg(patronymic).arg(address).arg(accountNumber).arg(productList);
}

bool operator == (const Seller& s1, const Seller& s2) {
    return static_cast<const Person&>(s1) == static_cast<const Person&>(s2) &&
           s1.accountNumber == s2.accountNumber;
}

ostream& operator << (ostream& os, const Seller& s) {
    os << static_cast<const Person&>(s);
    os << " " << s.accountNumber << " " << s.productList.toStdString();
    return os;
}

istream& operator >> (istream& is, Seller& s) {
    string prod;
    is >> static_cast<Person&>(s);
    is >> s.accountNumber >> prod;
    s.productList = QString::fromStdString(prod);
    return is;
}
