#include <iostream>
using namespace std;

struct inflatable
{
	char name[20];
	float volumn;
	double price;
	char tip[30];
};

int main()
{
	// ->, . �� ����
	inflatable* ps = new inflatable;
	cout << "����ǳ���� �̸��� �Է��ϼ���.";
	cin.get(ps->name, 20);
	cout << "���Ǹ� ������ ��Ʈ ������ �Է��ϼ���.";
	cin >> (*ps).volumn;
	cout << "������ �޷� ������ �Է��ϼ���.";
	cin >> ps->price;
	cout << "���� �Է��ϼ���.";
	cin.get(); // �׻� ���� �Է� �������� \n ������ �����ְ� �Է��� ����. (�Է� ���� ����)
	cin.get(ps->tip, 30);

	cout << "�̸�: " << ps->name << endl;
	cout << "����: " << (*ps).volumn << " cubic feet\n";
	cout << "����: " << ps->price << endl;
	cout << "��: " << ps->tip << endl;
	delete ps;
	return 0;
}