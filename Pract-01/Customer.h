#pragma once
#include <string>
#include "Person.h"
using namespace std;

class Customer : public Person
{
public:
	Customer();
	Customer(int id, string lastname, string name, string patronymic, string address, long creditCardNumber, int balance);
	Customer(const Customer& customer_1);
	~Customer();

	void print();

	void show() override {
		cout << "Customer class pure virtual method (show) called." << endl;
	}

	friend std::istream& operator >> (std::istream& is, Customer& customer_0);
	friend std::ostream& operator << (std::ostream& os, Customer& customer_0);
	friend bool operator == (const Customer& customer_1, const Customer& customer_2);

private:
	int creditCardNumber;
	int balance;
};
