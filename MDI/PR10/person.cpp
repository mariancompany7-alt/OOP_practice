#include "person.h"

Person::Person() : id(0) {}

Person::Person(int id, QString lastName, QString firstName, QString patronymic, QString address)
    : id(id), lastName(lastName), firstName(firstName), patronymic(patronymic), address(address) {}

Person::Person(const Person& other)
    : id(other.id), lastName(other.lastName), firstName(other.firstName),
    patronymic(other.patronymic), address(other.address) {}

bool operator == (const Person& p1, const Person& p2) {
    return p1.id == p2.id &&
           p1.lastName == p2.lastName &&
           p1.firstName == p2.firstName;
}

ostream& operator << (ostream& os, const Person& p) {
    os << p.id << " " << p.lastName.toStdString() << " "
       << p.firstName.toStdString() << " " << p.patronymic.toStdString();
    return os;
}

istream& operator >> (istream& is, Person& p) {
    string last, first, pat, addr;
    is >> p.id >> last >> first >> pat >> addr;
    p.lastName = QString::fromStdString(last);
    p.firstName = QString::fromStdString(first);
    p.patronymic = QString::fromStdString(pat);
    p.address = QString::fromStdString(addr);
    return is;
}
