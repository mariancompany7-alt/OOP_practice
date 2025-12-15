#pragma once
#include <iostream>
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