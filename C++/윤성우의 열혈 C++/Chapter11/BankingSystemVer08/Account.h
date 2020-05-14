#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int accID;
	int balance;
	char* cusName;

public:
	Account(int ID, int money, const char* name);
	Account(const Account& copy);           // 복사 생성자
	Account& operator=(const Account& ref); // 대입 연산자 오버로딩

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};
#endif