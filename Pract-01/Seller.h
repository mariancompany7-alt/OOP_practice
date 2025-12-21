#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Seller : public Person {
private:
	long accountNumber;
	string productList;

public:
	Seller();
	Seller(long accountNumber, string productList, int id, string lastname, string name, string patronymic, string address);
	Seller(const Seller& seller_1);
	~Seller();
	
	void print();

	void show() override {
		cout << "Seller class pure virtual method (show) called." << endl;
		cout << "accountNumber " << this->accountNumber << ", productList: " << this->productList << endl;
	}

	friend std::istream& operator >> (std::istream& is, Seller& seller_0);
	friend std::ostream& operator << (std::ostream& os, Seller& seller_0);
	friend bool operator == (const Seller& seller_1, const Seller& seller_2);
};