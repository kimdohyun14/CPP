#include <iostream>
using namespace std;
int main()
{
	int chest = 42;   // 10�� ������ ���
	int waist = 0x42; // 16�� ������ ���
	int inseam = 042; // 8�� ������ ���
	
	// �⺻������ cout�� ������ 10������ ����Ѵ�.
	cout << "�մ��� ���Ŵ� ������ �����ϴ�.\n";
	cout << "���� �ѷ� : " << chest << endl;
	cout << "�㸮 �ѷ� : " << waist << endl;  // 16 x 4 + 2 = 66
	cout << "�ν� �渮 : " << inseam << endl; // 8 x 4 + 2 = 34
	return 0;
}