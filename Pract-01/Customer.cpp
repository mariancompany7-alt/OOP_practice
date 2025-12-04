#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer() : id(0), lastname(""), name(""), patronymic(""), address(""), creditCardNumber(0), balance(0) {}

Customer::Customer(int id, string lastname, string name, string patronymic, string address, long creditCardNumber, int balance) : 
	id(id), lastname(lastname), name(name), patronymic(patronymic), address(address), creditCardNumber(creditCardNumber), balance(balance) {}

Customer::Customer(const Customer& customer_1) :
	id(customer_1.id), lastname(customer_1.lastname), name(customer_1.name), patronymic(customer_1.patronymic), 
	address(customer_1.address), creditCardNumber(customer_1.creditCardNumber), balance(customer_1.balance) {}

Customer::~Customer() {}

void Customer::print() {
	cout << this->id << " " << this->lastname << " " <<
		this->name << " " << this->patronymic << " " << this->address << " " << this->creditCardNumber << " " << this->balance << "$";
}

std::istream& operator >> (std::istream& is, Customer& customer_0) {
	is >> customer_0.id;
	is >> customer_0.lastname;
	is >> customer_0.name;
	is >> customer_0.patronymic;
	is >> customer_0.address;
	is >> customer_0.creditCardNumber;
	is >> customer_0.balance;
	return is;
}