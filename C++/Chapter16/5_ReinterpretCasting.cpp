#include <iostream>
using namespace std;

// reinterpret_cast : ������� �ڷ��������� �� ��ȯ

// �����Ϳ� ������ �ִ� ��� ������ �� ��ȯ�� ����Ѵ�.

int main()
{
	int num = 0x010203;
	char* ptr = reinterpret_cast<char*>(&num); // int�� ������ -> char�� ������ �� ��ȯ

	for (int i = 0; i < sizeof(num); i++)
	{
		cout << static_cast<int>(*(ptr + i)) << endl; // char�� -> int�� �� ��ȯ
	}
	return 0;
}