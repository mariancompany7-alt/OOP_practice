#include "Person.h"

Person::Person() : id(0), lastname("lastname"), name("name"), patronymic("patronymic"), address("address") {}

Person::Person(int id, string lastname, string name, string patronymic, string address)
	: id(id), lastname(lastname), name(name), patronymic(patronymic), address(address) {}

Person::Person(const Person& person_1) {
	this->id = person_1.id;
	this->lastname = person_1.lastname;
	this->name = person_1.name;
	this->patronymic = person_1.patronymic;
	this->address = person_1.address;
}

Person::~Person() {}

void Person::printGeneralInfo() {
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