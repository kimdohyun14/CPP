// support.cpp -- �ܺ� ������ ����Ѵ�
// external.cpp�� �������Ѵ�
#include <iostream>
extern double warming; // �ٸ� ���Ϸκ��� warming;�� ���

// �Լ� ����
void update(double dt);
void local();

void update(double dt)
{
	using namespace std;
	extern double warming; // ������ �缱��
	warming += dt;         // ���� warming�� ����Ѵ�
	cout << "���� warming�� " << warming;
	cout << "���� ���ŵǾ����ϴ�. \n";
}

void local()
{
	using namespace std;
	double warming = 0.8; // �� ������ �ܺ� ���� warming�� ������

	cout << "���� warming�� " << warming << "���Դϴ�. \n";
	cout << "�׷���, ���� warming�� " << ::warming;
	cout << "���Դϴ�. \n";
}