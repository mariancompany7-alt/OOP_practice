#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;

class Person {
private:
	int id;
	string lastname;
	string name;
	string patronymic;
	string address;

public:
	Person();
	Person(int id, string lastname, string name, string patronymic, string address);
	Person(const Person& person_1);

	virtual void show() = 0;

	virtual ~Person() {}

	int getId() const { return id; }

	void printGeneralInfo() const;

	friend std::istream& operator >> (std::istream& is, Person& person_1);
	friend std::ostream& operator << (std::ostream& os, Person& person_1);
	friend bool operator == (const Person& pearson_2, const Person& person_1);
};

Person::Person() : id(0), lastname("lastname"), name("name"), patronymic("patronymic"), address("address") {}

Person::Person(int id, string lastname, string name, string patronymic, string address)
	: id(id), lastname(lastname), name(name), patronymic(patronymic), address(address) {
}

Person::Person(const Person& person_1) {
	this->id = person_1.id;
	this->lastname = person_1.lastname;
	this->name = person_1.name;
	this->patronymic = person_1.patronymic;
	this->address = person_1.address;
}

void Person::printGeneralInfo() const {
	cout << this->id << " " << this->lastname << " " << this->name << " " << this->patronymic << " " << this->address << " ";
}

std::istream& operator >> (std::istream& is, Person& p) {
	cout << "id: ";
	is >> p.id;
	cout << "lastname: ";
	is >> p.lastname;
	cout << "name: ";
	is >> p.name;
	cout << "patronymic: ";
	is >> p.patronymic;
	cout << "address: ";
	is >> p.address;
	return is;
}

std::ostream& operator << (std::ostream& os, Person& p) {
	os << p.id << " ";
	os << p.lastname << " ";
	os << p.name << " ";
	os << p.patronymic << " ";
	os << p.address << " ";
	return os;
}

bool operator == (const Person& person_1, const Person& person_2) {
	return (person_1.id == person_2.id &&
		person_1.lastname == person_2.lastname &&
		person_1.name == person_2.name &&
		person_1.patronymic == person_2.patronymic &&
		person_1.address == person_2.address);
}



class Customer : public Person
{
public:
	Customer();
	Customer(int id, string lastname, string name, string patronymic, string address, long creditCardNumber, int balance);
	Customer(const Customer& c);
	~Customer();

	void print();

	void show() override {
		cout << "Customer class pure virtual method (show) called." << endl;
		printGeneralInfo();
		cout << "creditCardNumber: " << this->creditCardNumber << ", balance: " << this->balance << endl;
	}

	friend std::istream& operator >> (std::istream& is, Customer& customer_0);
	friend std::ostream& operator << (std::ostream& os, Customer& customer_0);
	friend bool operator == (const Customer& customer_1, const Customer& customer_2);

private:
	int creditCardNumber;
	int balance;
};

Customer::Customer() : Person(), creditCardNumber(0), balance(0) {}

Customer::Customer(int id, string lastname, string name, string patronymic, string address, long creditCardNumber, int balance)
	: Person(id, lastname, name, patronymic, address), creditCardNumber(creditCardNumber), balance(balance) {
}

Customer::Customer(const Customer& c)
	: Person(c), creditCardNumber(c.creditCardNumber), balance(c.balance) {
}

Customer::~Customer() {}

void Customer::print() {
	printGeneralInfo();
	cout << this->creditCardNumber << " " << this->balance << "$";
}

std::istream& operator >> (std::istream& is, Customer& c) {
	is >> (Person&)c;
	cout << "creditCardNumber: ";
	is >> c.creditCardNumber;
	cout << "balance: ";
	is >> c.balance;
	return is;
}

std::ostream& operator << (std::ostream& os, Customer& c) {
	os << (Person&)c;
	os << c.creditCardNumber << " ";
	os << c.balance << "$";
	return os;
}

bool operator == (const Customer& customer_1, const Customer& customer_2) {

	return (static_cast<const Person&>(customer_1) == static_cast<const Person&>(customer_2)) &&
		(customer_1.creditCardNumber == customer_2.creditCardNumber &&
			customer_1.balance == customer_2.balance);
}

class Seller : public Person {
private:
	long accountNumber;
	string productList;

public:
	Seller();
	Seller(int id, string lastname, string name, string patronymic, string address, long accountNumber, string productList);
	Seller(const Seller& seller_1);
	~Seller();

	void print();

	void show() override {
		cout << "Seller class pure virtual method (show) called." << endl;
		printGeneralInfo();
		cout << "accountNumber " << this->accountNumber << ", productList: " << this->productList << endl;
	}

	friend std::istream& operator >> (std::istream& is, Seller& seller_0);
	friend std::ostream& operator << (std::ostream& os, Seller& seller_0);
	friend bool operator == (const Seller& seller_1, const Seller& seller_2);
};

Seller::Seller() : Person(), accountNumber(0), productList("productList") {};

Seller::Seller(int id, string lastname, string name, string patronymic, string address, long accountNumber, string productList)
	: Person(id, lastname, name, patronymic, address), accountNumber(accountNumber), productList(productList) {
}

Seller::Seller(const Seller& seller_1)
	: Person(seller_1), accountNumber(seller_1.accountNumber), productList(seller_1.productList) {
}

Seller::~Seller() {}

void Seller::print() {
	printGeneralInfo();
	cout << accountNumber << " " << productList;
}

std::istream& operator >> (std::istream& is, Seller& seller) {
	is >> (Person&)seller;
	cout << "accountNumber: ";
	is >> seller.accountNumber;
	cout << "productList: ";
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
	return (static_cast<const Person&>(seller_1) == static_cast<const Person&>(seller_2)) &&
		(seller_1.accountNumber == seller_2.accountNumber &&
			seller_1.productList == seller_2.productList);
}

static void menu() {
	cout << "Menu:" << endl;
	cout << "1. Додати Customer" << endl;
	cout << "2. Додати Seller" << endl;
	cout << "3. Пошук об'єкта" << endl;
	cout << "4. Вихід" << endl;
	cout << "Ваш вибір:" << endl;
}

int main() {

	srand(static_cast<unsigned>(time(nullptr)));

	list<int> l1;
	list<int> l2;

	for (int i = 0; i < 10; ++i) {
		int num = rand() % 100;
		if (num % 2 == 0) {
			num++;
		}
		l1.push_back(num);
	}

	l2.resize(10);

	for (list<int>::iterator it = l2.begin(); it != l2.end(); ++it) {

		int num = rand() % 100;
		if (num % 2 != 0) {
			num++;
		}
		*it = num;
	}

	l1.sort();
	l2.sort();

	list<int> l3;

	merge(l1.begin(), l1.end(),
		l2.begin(), l2.end(),
		back_inserter(l3));

	cout << "List #1:  ";
	for (const auto& el : l1) {
		cout << el << " ";
	}
	cout << endl;

	cout << "List #2:  ";
	for (const auto& el : l2) {
		cout << el << " ";
	}
	cout << endl;

	cout << "List #3:  ";
	for (const auto& el : l3) {
		cout << el << " ";
	}
	cout << endl;

	map<int, Person*> m1;

	int choice = 0;
	while (choice != 4) {

		menu();
		cin >> choice;

		switch (choice) {
		case 1: {
			Customer* newCust = new Customer();

			cout << "Ввеіть дані  ";

			cin >> *newCust;

			m1[newCust->getId()] = newCust;

			cout << "Customer object created successfuly!" << endl;

			break;
		}

		case 2: {
			Seller* newSell = new Seller();

			cout << "Ввеіть дані  ";

			cin >> *newSell;

			m1[newSell->getId()] = newSell;

			cout << "Seller object created successfuly!" << endl;

			break;
		}

		case 3: {
			int key;
			cout << "Введіть ключ (ID): ";
			cin >> key;

			auto it = m1.find(key);

			if (it != m1.end()) {

				it->second->show();
			}
			else {
				cout << "Обєкт з ID " << key << " не знайдено!" << endl;
			}
			break;
		}

		case 4:
			cout << "Exiting";
			break;
		}
	}

	for (auto& pair : m1) {
		delete pair.second;
	}

	return 0;
}