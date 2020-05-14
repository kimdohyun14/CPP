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
	cout << "계좌ID: " << endl;
	cout << "이  름: " << cusName << endl;
	cout << "잔  액: " << balance << endl;
}

void Account::Deposit(int money)
{
	balance += money;
}

Account::~Account()
{
	delete[] cusName;
}
