#include <iostream>
using namespace std;
int main()
{
	int chest = 42;
	int waist = 42;
	int inseam = 42;

	cout << "���Ŵ� ������ �����ϴ�.\n";
	cout << "���� �ѷ� : " << chest << endl;
	cout << hex; // ������ �ٲٴ� ������ (std �̸������ȿ� �ִ�.)
	cout << "�㸮 �ѷ� : " << waist << endl;
	cout << oct; // ������ �ٲٴ� ������
	cout << "�ν� ���� : " << inseam << endl;
	return 0;
}