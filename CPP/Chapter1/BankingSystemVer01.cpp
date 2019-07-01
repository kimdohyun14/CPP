#include <iostream>
#include <cstring>
using namespace std;
const int NAME_LEN = 20;

void ShowMenu();      //�޴����
void MakeAccount();   //���°���
void DepositMoney();  //�Ա�
void WithDrawMoney(); //���
void ShowAllAccInfo();//�������� ��ü ���

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct {
	int accID;           //���¹�ȣ
	char cusName[NAME_LEN]; //���̸�
	int balance;         //���ܾ�
}Account;

Account accArr[100]; //�� 100�� ����
int accNum = 0;      //����� Account ��

int main() {
	int select;

	while (1) {
		ShowMenu();
		cout << "���� : ";
		cin >> select;
		cout << endl;
		switch (select) {
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithDrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			cout << "���α׷��� �����մϴ�. " << endl;
			return 0;
		default:
			cout << "illegal selection.." << endl;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. ��    ��" << endl;
	cout << "3. ��    ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void MakeAccount() {
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�̸�: "; cin >> name;
	cout << "�Աݾ�: "; cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney() {
	int money;
	int id;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "����ID�� ��ġ���� �ʽ��ϴ�." << endl << endl;
}

void WithDrawMoney() {
	int money;
	int id;
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) {
				cout << "�ܾ��� �����մϴ�" << endl << endl;
				return;
			}
			accArr[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "����ID�� ��ġ���� �ʽ��ϴ�." << endl << endl;
}

void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "����ID: " << accArr[i].accID << endl;
		cout << "�� ��: " << accArr[i].cusName << endl;
		cout << "�� ��: " << accArr[i].balance << endl << endl;
	}
}