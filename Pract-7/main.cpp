#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
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
	is >> p.id;
	is >> p.lastname;
	is >> p.name;
	is >> p.patronymic;
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
	is >> c.creditCardNumber;
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
	return (static_cast<const Person&>(seller_1) == static_cast<const Person&>(seller_2)) &&
		(seller_1.accountNumber == seller_2.accountNumber &&
			seller_1.productList == seller_2.productList);
}

void menu() {
	cout << "Menu:" << endl;
	cout << "1. Додати Customer" << endl;
	cout << "2. Додати Seller" << endl;
	cout << "3. Вихід" << endl;
}

void customerFillData(vector<Person*>& p) {

	int id, cardNumber, balance;
	string name, lastname, patronymic, address;

	cout << "Введіть дані для Customer ";
	cout << "id: "; cin >> id;
	cout << "name: "; cin >> name;
	cout << "lastname: "; cin >> lastname;
	cout << "patronymic: "; cin >> patronymic;
	cout << "address: "; cin >> address;
	cout << "cardNumber: "; cin >> cardNumber;
	cout << "balance: "; cin >> balance;

	p.push_back(new Customer(id, lastname, name, patronymic, address, cardNumber, balance));
	cout << "Customer object successfuly created!" << endl;
}

void sellerFillData(vector<Person*>& p) {

	int id, accountNumber;
	string name, lastname, patronymic, address, productList;

	cout << "Введіть дані для Customer ";
	cout << "id: "; cin >> id;
	cout << "name: "; cin >> name;
	cout << "lastname: "; cin >> lastname;
	cout << "patronymic: "; cin >> patronymic;
	cout << "address: "; cin >> address;
	cout << "accountNumber: "; cin >> accountNumber;
	cout << "productList: "; cin >> productList;

	p.push_back(new Seller(id, lastname, name, patronymic, address, accountNumber, productList));
	cout << "Seller object successfuly created!" << endl;
}

void printVectorResult(const vector<Person*>& p) {

	for (const auto* it : p) {
		const_cast<Person*>(it)->show();
	}
}

int main() {

	setlocale(LC_ALL, "ukr");
   
    srand(static_cast<unsigned int>(time(0)));

    vector<int> v1(10);
    vector<int> v2(10);

    for (size_t i = 0; i < v1.size(); ++i) {
        int num = rand() % 100;
        if (num % 2 == 0) {
            num++;
        }
        v1[i] = num;
        cout << v1[i] << " ";
    }
    cout << endl;

    for (auto it = v2.begin(); it != v2.end(); ++it) {
        int num = rand() % 100;
        if (num % 2 != 0) {
            num++;
        }
        *it = num;
        cout << *it << " ";
    }
    cout << endl;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    vector<int> v3(v1.size() + v2.size());
    merge(v1.begin(), v1.end(),
        v2.begin(), v2.end(),
        v3.begin());

    for (size_t i = 0; i < v3.size(); ++i) {
        cout << v3[i] << " ";
    }
	cout << endl;

	vector<Person*> p;

	int choice = 0;
	while (choice != 3) {

		menu();
		cin >> choice;

		switch (choice) {

		case 1: customerFillData(p);
			break;
		case 2: sellerFillData(p);
			break;
		case 3: cout << "Exiting";
			break;
		}
	}

	vector<Person*> pCopy = p;

	auto it1 = p.begin();
	while (it1 != p.end()) {

		if (dynamic_cast<Customer*>(*it1) != nullptr) {
			it1 = p.erase(it1);
		}
		else {

			++it1;
		}
	}

	auto it2 = pCopy.begin();
	while (it2 != pCopy.end()) {

		if (dynamic_cast<Seller*>(*it2) != nullptr) {
			it2 = pCopy.erase(it2);
		}
		else {

			++it2;
		}
	}

	cout << "\nВидалено всі елементи першого підкласу:" << endl;
	printVectorResult(p);
	cout << "\nВидалено всі елементи другого підкласу::" << endl;
	printVectorResult(pCopy);

	for (auto* it : p) delete it;
	for (auto* it : pCopy) delete it;

    return 0;
}
