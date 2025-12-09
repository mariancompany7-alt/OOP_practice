#include "Seller.h"
#include <iostream>
using namespace std;

Seller::Seller() : Person(), accountNumber(0), productList("productList") {};

Seller::Seller(long accountNumber, string productList, int id, string lastname, string name, string patronymic, string address)
	: Person(id, lastname, name, patronymic, address), accountNumber(accountNumber), productList(productList) {}

Seller::Seller(const Seller& seller_1)
	: Person(seller_1), accountNumber(seller_1.accountNumber), productList(seller_1.productList) {}

Seller::~Seller() {}

void Seller::print() {
	printGeneralInfo();
	cout << accountNumber << " " << productList;
}

std::istream& operator >> (std::istream& is, Seller& seller) {
	is >> (Person&)seller;
	is >> seller.accountNumber;
	is >> seller.productList;
	return is;
}

std::ostream& operator << (std::ostream& os, Seller& seller) {
	os << (Person&)seller;
	os << seller.accountNumber << " ";
	os << seller.productList << " ";
	return os;
}

bool operator == (const Seller& seller_1, const Seller& seller_2) {
    return (static_cast<const Person&>(seller_1) == static_cast<const Person&>(seller_2)),
		(seller_1.accountNumber == seller_2.accountNumber &&
            seller_1.productList == seller_2.productList);
}