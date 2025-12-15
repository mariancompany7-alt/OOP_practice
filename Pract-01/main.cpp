#include "Customer.h"
#include "Person.h"
#include "Seller.h"
#include <iostream>
using namespace std;

 static int menu() {
	Person* ptr = nullptr;
	int choice = 0;

	while (choice != 3)	{

		cout << "Menu:\n";
		cout << "1. Create Customer\n";
		cout << "2. Create Seller\n";
		cout << "3. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
		{
			cout << "Creating Customer:\n";
			ptr = new Customer();
			Customer person_0;
			ptr->show();
			delete ptr;
			break;
		}
		case 2:
		{
			cout << "Creating Seller:\n";
			ptr = new Seller();
			Seller seller_0;
			ptr->show();
			delete ptr;
			break;
		}
		case 3:
		{
			cout << "Exiting the program.\n";
			break;
			}
		}
	}
	return 0;
}

int main() {

	setlocale(LC_ALL, "Ukrainian");

	int const SIZE = 5;
	Person* p[SIZE];

	cout << "--- Заповнення масиву вказівників ---\n";

	menu();

	p[0] = new Customer();
	p[1] = new Customer();
	p[2] = new Seller();
	p[3] = new Seller();
	p[4] = new Customer();

	cout << "\n--- Виклик методу show() для кожного об'єкта ---\n";
	for (int i = 0; i < SIZE; i++) {
		p[i]->show();
	}

	for (int i = 0; i < SIZE; i++) {
		delete p[i];
	}

	return 0; 
}
