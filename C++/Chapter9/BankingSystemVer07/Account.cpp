#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int ID, int money, const char* name) // constructor
	:accID(ID), balance(money)
{
	int len = strlen(name) + 1;
	cusName = new char[len];
	strcpy(cusName, name);
}

Account::Account(const Account& copy) // deep copy (copy constructor)
	:accID(copy.accID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}

int Account::GetAccID() const
{
	return accID;
}

int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;

	balance -= money;
	return money;
}

void Account::ShowAccInfo() const
{
	cout << "°èÁÂID: " << endl;
	cout << "ÀÌ  ¸§: " << cusName << endl;
	cout << "ÀÜ  ¾×: " << balance << endl;
}

void Account::Deposit(int money)
{
	balance += money;
}

Account::~Account()
{
	delete[] cusName;
}