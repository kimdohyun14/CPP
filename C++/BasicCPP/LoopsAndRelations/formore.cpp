#include <iostream>
using namespace std;

// �迭�� ���� ������ const ������ �����ϴ� ���� ���� �����̴�.
// �迭�� �����̳� for ������ ���� ������ �迭 ũ�Ⱑ �ʿ��� �� ����� �� �ִ�.
const int ArSize = 16;
int main()
{
	long long factorials[ArSize];
	factorials[1] = factorials[0] = 1LL; // 1!=1, 0!=1

	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];

	// ����� �ſ� ������ �����Ѵ�.
	for (int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << endl;

	return 0;
}