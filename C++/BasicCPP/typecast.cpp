#include <iostream>
using namespace std;
int main()
{
	int auks, bats, coots;

	// �� ���� double������ ���� ��, �� ���� int������ ��ȯ�Ͽ� ����
	auks = 19.99 + 11.99;

	bats = (int)19.99 + (int)11.99;  // ���� C ��Ÿ��
	coots = int(19.99) + int(11.99); // �Ž� C++ ��Ÿ��
	cout << "�ٴٿ��� = " << auks << ", ���� = " << bats;
	cout << ", �˵տ��� = " << coots << endl;

	char ch = 'Z';
	cout << "�ڵ� " << ch << " �� ���� ";
	cout << int(ch) << endl;
	cout << "�ڵ� Z�� ���� ";
	cout << static_cast<int>(ch) << endl; // C++������ �������� 4���� �������� ��ȯ �����ڸ� ����Ѵ�.

	// C++11 auto(�ʱ�ȭ�ϴ� ���� ���� �������� �߷��� �� �ִ�.)
	// ������ �������� �ٷ� �� �ſ� �����ϴ�. (�ʹ� �� ����Ÿ��)
	auto n = 100; // int
	auto x = 1.5; // double
	auto y = 1.3e12L; // long double
	return 0;
}