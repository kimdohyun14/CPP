#include <iostream>
#define SIZE 100
using namespace std;

/* C++�� ���� ���� �з������� ������ �ִ� ��������� C���� ������ ���α׷��� ���.
   C++�� ��ü �߽��� ����̸� C���� �Լ� ����� ���
   C++�� C����� ����ü(struct) ��ſ� Ŭ����(Class)�� ���
   C++�� ���������� ���� ó��(Exception Handling) ����� �����Ѵ�.*/

int* arr;

int main()
{
	arr = new int[SIZE]; // �����Ҵ�
	for (int i = 0; i < SIZE; i++) arr[i] = i;
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << ' ';
	}
	delete arr; // �Ҵ� ����
	return 0;
}