#include "Customer.h"
#include "Person.h"
#include "Seller.h"
#include <iostream>
using namespace std;

int main() {

	cout << "--- class Person ---\n";
	Person person_1;
	Person person_2(2, "Ivanov", "Ivan", "Ivanovich", "Lenina");
	Person person_3 = person_2;
	cout << "\nOutput person_3 (copy of person_2): ";
	person_3.printGeneralInfo();

	cout << "\nInput id, name, lastname, patronymic, address: ";
	std::cin >> person_2;
	cout << "\nOutput: ";
	std::cout << person_2;

	cout << endl;
	if (person_1 == person_2) {
		cout << "\nObject (person_1) = object (person_2)";
	}
	else {
		cout << "\nObject (person_1) do not equel object (person_2)";
	}

	cout << "\n\n--- class Customer ---\n";
	Customer customer_0;
	Customer customer_1(1, "Perchyshyn", "Marian", "Andriyovich", "Morozenka", 109023457, 1500);
	Customer customer_2 = customer_1;
	cout << "\nOutput customer_2 (copy of customer_1): ";
	customer_2.print();

	cout << "\nInput id, name, lastname, patronymic, address, creditCardNumber, balance: ";
	std::cin >> customer_0;
	cout << "\nOutput: ";
	std::cout << customer_0;

	cout << endl;
	if (customer_1 == customer_2) {
		cout << "\nObject (customer_1) = object (customer_2)";
	}
	else {
		cout << "\nObject (customer_1) do not equel object (customer_2)";
	}

	cout << "\n\n--- class Seller ---\n";
	Seller seller_0;
	Seller seller_1(123456789, "Apples, Bananas", 3, "Petrov", "Petr", "Petrovich", "Kirova");
	Seller seller_2 = seller_1;
	cout << "\nOutput seller_2 (copy of seller_1): ";
	seller_2.print();

	cout << "\nInput id, name, lastname, patronymic, address, accountNumber, productList: ";
	std::cin >> seller_0;
	cout << "\nOutput: ";
	std::cout << seller_0;

	cout << endl;
	if (seller_1 == seller_2) {
		cout << "\nObject (seller_1) = object (seller_2)";
	}
	else {
		cout << "\nObject (seller_1) do not equel object (seller_2)";
	}

	return 0; 
}
