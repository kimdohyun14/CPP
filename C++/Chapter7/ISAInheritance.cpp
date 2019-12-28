#include <iostream>
#include <cstring>
using namespace std;

class Computer {
private:
	char owner[50];
public:
	Computer(const char* name) {
		strcpy(owner, name);
		cout << "Computer������" << endl;
	}
	void Calculate() {
		cout << "��û ������ ����մϴ�." << endl;
	}
	~Computer() {
		cout << "Computer�Ҹ���" << endl;
	}
};

class NotebookComp : public Computer {
private:
	int Battery;
public:
	NotebookComp(const char* name, int initChag)
		:Computer(name), Battery(initChag){
		cout << "NotebookComp������" << endl;
	}
	void Charging() {
		Battery += 5;
	}
	void UseBattery() { Battery -= 1; }
	void MovingCal() {
		if (GetBatteryInfo() < 1) {
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		cout << "�̵��ϸ鼭 ";
		Calculate();
		UseBattery();
	}
	int GetBatteryInfo() { return Battery; }
	~NotebookComp() {
		cout << "NotebookComp�Ҹ���" << endl;
	}
};

class TableNotebook : public NotebookComp {
private:
	char regstPenModel[50];
public:
	TableNotebook(const char* name, int initChag, const char* pen)
		:NotebookComp(name, initChag) {
		strcpy(regstPenModel, pen);
		cout << "TableNotebook������" << endl;
	}
	void Write(const char* penInfo) {
		if (GetBatteryInfo() < 1) {
			cout << "������ �ʿ��մϴ�." << endl;
			return;
		}
		if (strcmp(regstPenModel, penInfo) != 0) {
			cout << "��ϵ� ���� �ƴմϴ�." << endl;
			return;
		}
		cout << "�ʱ� ������ ó���մϴ�." << endl;
		UseBattery();
	}
	~TableNotebook() {
		cout << "TableNotebook�Ҹ���" << endl;
	}
};

int main() {
	NotebookComp nc("������", 5);
	TableNotebook tn("������", 5, "ISE-241-242");
	nc.MovingCal();
	tn.Write("ISE-241-242");
	return 0;
}