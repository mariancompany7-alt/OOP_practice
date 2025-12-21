#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <iostream>

using namespace std;

class Person {
protected:
    int id;
    QString lastName;
    QString firstName;
    QString patronymic;
    QString address;

public:
    Person();
    Person(int id, QString lastName, QString firstName, QString patronymic, QString address);
    Person(const Person& other);
    virtual ~Person() {}

    virtual QString getInfo() const = 0;

    int getId() const { return id; }
    QString getLastName() const { return lastName; }
    QString getFirstName() const { return firstName; }
    QString getPatronymic() const { return patronymic; }
    QString getAddress() const { return address; }

    // Friend operators from Pract-01
    friend istream& operator >> (istream& is, Person& p);
    friend ostream& operator << (ostream& os, const Person& p);
    friend bool operator == (const Person& p1, const Person& p2);
};

#endif // PERSON_H
