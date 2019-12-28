#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

//Entity Ŭ����
class Account {
private:
	int accID;       //���¹�ȣ
	int balance;     //��	 ��
	char* cusName;  //���̸�

public:
	Account(int ID, int money, char* name);
	Account(const Account& copy);

	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();
};

Account::Account(int ID, int money, char* name)
	:accID(ID), balance(money) {
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& copy) : accID(copy.accID), balance(copy.balance) {
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}

int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) {
	balance += money;
}

int Account::Withdraw(int money) {
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}

void Account::ShowAccInfo() const {
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
}
Account::~Account() {
	delete[]cusName;
}

//��Ʈ��(Control) Ŭ����
class AccountHandler {
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};

void AccountHandler::ShowMenu(void) const {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl << endl;
}

void AccountHandler::MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��  ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);
}

void AccountHandler::DepositMoney(void) {
	int money;
	int id;
	cout << "[��  ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl;
}

void AccountHandler::WithdrawMoney(void) {
	int money;
	int id;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
}

AccountHandler::AccountHandler() : accNum(0)
{ }

void AccountHandler::ShowAllAccInfo(void) const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++)
		delete[] accArr[i];
}


int main() {
	AccountHandler manager;
	int select;

	while (1) {
		manager.ShowMenu();
		cout << "���� : ";
		cin >> select;
		cout << endl;
		switch (select) {
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "illegal selection.." << endl;
		}
	}
	return 0;
}
