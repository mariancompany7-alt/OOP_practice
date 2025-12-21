#include "customer.h"

Customer::Customer()
    : id(0), lastName(""), firstName(""), patronymic(""),
    address(""), creditCardNumber(0), balance(0.0) {}

Customer::Customer(int id, QString lastName, QString firstName, QString patronymic,
                   QString address, long creditCardNumber, double balance)
    : id(id), lastName(lastName), firstName(firstName), patronymic(patronymic),
    address(address), creditCardNumber(creditCardNumber), balance(balance) {}

Customer::Customer(const Customer& other)
    : id(other.id), lastName(other.lastName), firstName(other.firstName),
    patronymic(other.patronymic), address(other.address),
    creditCardNumber(other.creditCardNumber), balance(other.balance) {}

Customer::~Customer() {}

QString Customer::toString() const {
    return ("\nid: " + QString::number(id) + "\nlastname: " + lastName + "\nfirstname: " + firstName
            + "\npatronymic: " + patronymic + "\naddress: " + address + "\nnumber of card: "
            + QString::number(creditCardNumber) + "\nbalance: " + QString::number(balance));
}
