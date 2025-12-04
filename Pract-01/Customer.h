#pragma once
#include <string>
using namespace std;

class Customer
{
public:
	Customer();
	Customer(int id, string lastname, string name, string patronymic, string address, long creditCardNumber, int balance);
	Customer(const Customer& customer);
	~Customer();

	void print();

	friend std::istream& operator >> (std::istream& is, Customer& customer_0);
	friend std::ostream& operator << (std::ostream& os, Customer& customer_0);

private:
	int id;
	string lastname;
	string name;
	string patronymic;
	string address;
	int creditCardNumber;
	int balance;
};
