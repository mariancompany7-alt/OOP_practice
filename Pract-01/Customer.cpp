#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer() : Person(), creditCardNumber(0), balance(0) {}

Customer::Customer(int id, string lastname, string name, string patronymic, string address, long creditCardNumber, int balance)
	: Person(id, lastname, name, patronymic, address), creditCardNumber(creditCardNumber), balance(balance) {}

Customer::Customer(const Customer& customer_1)
	: Person(customer_1), creditCardNumber(customer_1.creditCardNumber), balance(customer_1.balance) {}

Customer::~Customer() {}

void Customer::print() {
	cout << "Object (customer_2) ";
	printGeneralInfo();
	cout << this->creditCardNumber << " " << this->balance << "$";
}

std::istream& operator >> (std::istream& is, Customer& customer) {
	is >> (Person&)customer;
	is >> customer.creditCardNumber;
	is >> customer.balance;
	return is;
}

std::ostream& operator << (std::ostream& os, Customer& customer) {
	os << (Person&)customer;
	os << customer.creditCardNumber << " ";
	os << customer.balance << "$";
	return os;
}

bool operator == (const Customer& customer_1, const Customer& customer_2) {

	return (static_cast<const Person&>(customer_1) == static_cast<const Person&>(customer_2)), 
		(customer_1.creditCardNumber == customer_2.creditCardNumber &&
		customer_1.balance == customer_2.balance);
}