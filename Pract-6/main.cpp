#include <iostream>
#include <windows.h>
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

std::istream& operator >> (std::istream& is, Person& person_1) {
	is >> person_1.id;
	is >> person_1.lastname;
	is >> person_1.name;
	is >> person_1.patronymic;
	is >> person_1.address;
	return is;
}

std::ostream& operator << (std::ostream& os, Person& person_1) {
	os << person_1.id << " ";
	os << person_1.lastname << " ";
	os << person_1.name << " ";
	os << person_1.patronymic << " ";
	os << person_1.address << " ";
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
	Customer(const Customer& customer_1);
	~Customer();

	void print();

	void show() override {
		cout << "Customer class pure virtual method (show) called." << endl;
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

Customer::Customer(const Customer& customer_1)
	: Person(customer_1), creditCardNumber(customer_1.creditCardNumber), balance(customer_1.balance) {
}

Customer::~Customer() {}

void Customer::print() {
	printGeneralInfo();
	cout << this->creditCardNumber << " " << this->balance << "$";
}

std::istream& operator >> (std::istream& is, Customer& customer) {
	is >> (Person&)customer;
	is >> customer.creditCardNumber;
	is >> customer.balance;
	return is;
}

std::ostream& operator << (std::ostream& os, Customer& customer) {
	os << (Person&)customer;
	os << customer.creditCardNumber << " ";
	os << customer.balance << "$";
	return os;
}

bool operator == (const Customer& customer_1, const Customer& customer_2) {

	return (static_cast<const Person&>(customer_1) == static_cast<const Person&>(customer_2)),
		(customer_1.creditCardNumber == customer_2.creditCardNumber &&
			customer_1.balance == customer_2.balance);
}

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

Seller::Seller() : Person(), accountNumber(0), productList("productList") {};

Seller::Seller(long accountNumber, string productList, int id, string lastname, string name, string patronymic, string address)
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
	return (static_cast<const Person&>(seller_1) == static_cast<const Person&>(seller_2)),
		(seller_1.accountNumber == seller_2.accountNumber &&
			seller_1.productList == seller_2.productList);
}



template<typename T>
class Vector {
	T* array;
	int size;
	int capacity;
public:
	Vector() {
		capacity = 10;
		size = 0;
		array = new T[capacity];
	}

	~Vector() {
		delete[] array;
	}

	int getSize();
	int getCapacity();
	void pushBack(T element);
	void popBack();
	T at(int index);
	T operator[](int index);
};

template<typename T>
int Vector<T>::getSize() {
	return size;
}

template<typename T>
int Vector<T>::getCapacity() {
	return capacity;
}

template<typename T>
void Vector<T>::pushBack(T element) {

	if (size == capacity) {
		capacity *= 2;
		T* newArray = new T[capacity];

		for (int i = 0; i < size; i++) {
			newArray[i] = array[i];
		}
		delete[] array;
		array = newArray;
	}

	array[size] = element;
	size++;
}

template<typename T>
void Vector<T>::popBack() {
	if (size > 0) {
		size--;
	}
}

template<typename T>
T Vector<T>::at(int index) {

	if (index < size && index >= 0) {
		return array[index];
	}
	return T();
}

template<typename T>
T Vector<T>::operator[] (int index) {
	return array[index];
}

int main() {

	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	cout << "Перевірка роботи Vector<int>" << endl;
	Vector<int> v1;
	v1.pushBack(10);
	v1.pushBack(20);
	cout << "Отримання елемента за індексом 1: " << v1[1] << endl;

	cout << "Перевірка роботи Vector<long>" << endl;
	Vector<long> v2;
	v2.pushBack(13425726482);
	v2.pushBack(76762642);
	cout << "Отримання елемента за індексом 0: " << v2[0] << endl;
	
	Vector<float> v3;
	for (int i = 0; i < 15; i++) {
		v3.pushBack(i * 1.1f);
	}
	cout << "Float Vector capacity  після розширення: " << v3.getCapacity() << endl;
	
	Vector<Person*> p;
	p.pushBack(new Customer(1, "T", "T", "G.", "Kyiv", 11112222, 5000));
	p.pushBack(new Customer(2, "M", "M", "M", "M", 134324, 1000));

	p.pushBack(new Seller(927127, "B, M", 3, "F", "F", "F", "F"));
	p.pushBack(new Seller(927137, "B, B", 4, "F", "C", "F", "C"));

	cout << "Виклик віртуального методу для кожного об'єкта" << endl;
	for (int i = 0; i < p.getSize(); i++) {
		p[i]->show();
	}

	for (int i = 0; i < p.getSize(); i++) {
		delete p[i];
	}

	return 0;
}