// external.cpp -- �ܺ� ������
// support.cpp�� �������Ѵ�
#include <iostream>
using namespace std;
// �ܺ� ����
double warming = 0.3;
// �Լ� ����
void update(double dt);
void local();

int main() // ���� ������ ����Ѵ�
{
	cout << "���� warming�� " << warming << "���Դϴ�. \n";
	update(0.1); // warming�� �����ϴ� �Լ��� ȣ��
	cout << "���� warming�� " << warming << "���Դϴ�. \n";
	local(); // ���� warming���� �Լ��� ȣ��
	cout << "���� warming�� " << warming << "���Դϴ�. \n";
	return 0;
}