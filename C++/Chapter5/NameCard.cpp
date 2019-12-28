#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS {
	enum{CLERK, SENIOR, ASSIST, MANAGER};

	void ShowPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
		}
	}
}

class NameCard {
private:
	char * name;
	char * company;
	char * phone;
	int position;
public:
	NameCard(const char * _name, const char * _company, const char * _phone, int pos) 
		:position(pos) {
		name = new char(strlen(_name) + 1);
		company = new char(strlen(_company) + 1);
		phone = new char(strlen(_phone) + 1);

		strcpy(name, _name);
		strcpy(company, _company);
		strcpy(phone, _phone);
	}
	NameCard(const NameCard &copy) :position(copy.position) {
		name = new char(strlen(copy.name) + 1);
		company = new char(strlen(copy.company) + 1);
		phone = new char(strlen(copy.phone) + 1);
		strcpy(name, copy.name);
		strcpy(company, copy.company);
		strcpy(phone, copy.phone);
	}
	void ShowNameCardInfo() const {
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << phone << endl;
		cout << "����: "; COMP_POS::ShowPositionInfo(position);
		cout << endl;
	}
	~NameCard() {
		delete[]name;
		delete[]company;
		delete[]phone;
	}
};

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	copy1.ShowNameCardInfo();
	return 0;
}