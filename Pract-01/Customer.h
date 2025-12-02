#pragma once
#include <string>
using namespace std;

class Customer
{
public:
	Customer();
	~Customer();

private:
	int id;
	string lastname;
	string name;
	string patronymic;
	string address;
	int creditCardNumber;
	int balance;
};
// id, прізвище, ім'я, по батькові, адреса, номер кредитної
// картки, баланс рахунку(кількість грошей)