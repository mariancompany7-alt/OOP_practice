#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QMainWindow>

class Customer {
public:
    Customer();

    Customer(int id, QString lastName, QString firstName, QString patronymic,
             QString address, long creditCardNumber, double balance);

    Customer(const Customer& other);

    ~Customer();

    QString toString() const;

    int getId() const { return id; }
    QString getLastName() const { return lastName; }
    QString getFirstName() const { return firstName; }
    QString getPatronymic() const { return patronymic; }
    QString getAddress() const { return address; }
    long getCreditCardNumber() const { return creditCardNumber; }
    double getBalance() const { return balance; }

private:
    int id;
    QString lastName;
    QString firstName;
    QString patronymic;
    QString address;
    long creditCardNumber;
    double balance;
};

#endif // CUSTOMER_H
