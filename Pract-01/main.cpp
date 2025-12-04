#include "Customer.h"
#include <iostream>
using namespace std;

int main() {
	Customer customer_0;
	Customer customer_1(1, "Perchyshyn", "Marian", "Andriyovich", "Morozenka", 1090234576540987, 1500);
	Customer customer_2 = customer_1;

	customer_2.print();

	cout << "\nInput id, name, lastname, patronymic, address, creditCardNumber, balance: ";
	std::cin >> customer_0;
	cout << "\nOutput: ";
	std::cout << customer_0;

	if (customer_1 == customer_2) {
		cout << "\nObject (customer_1) = object (customer_2)";
	}
	else {
		cout << "\nObject (customer_1) do not equel object (customer_2)";
	}

	return 0; 
}
