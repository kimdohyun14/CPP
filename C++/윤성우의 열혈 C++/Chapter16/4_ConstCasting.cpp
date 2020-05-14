#include <iostream>
using namespace std;

void ShowString(char* str)
{
	cout << str << endl;
}

void ShowAddResult(int& n1, int& n2)
{
	cout << n1 + n2 << endl;
}

// const_cast : const�� ������ ����
// �����Ϳ� �������� const ������ �����ϴ� �� ��ȯ�̴�.

// �Լ��� �������� �� const �������� ���� ���� ����ġ�� �߻��ؼ� ������ ������ �Ұ����� ��쿡 ���

int main()
{
	const char* name = "Kim Do Hyun";
	ShowString(const_cast<char*>(name)); // const char* -> char* �� �� ��ȯ�Ͽ� �Լ��� ���������� �Ѵ�.

	const int& num1 = 100;
	const int& num2 = 200;
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2)); // const int& -> int&�� �� ��ȯ
	return 0;
}