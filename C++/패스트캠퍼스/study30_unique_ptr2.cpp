#include <iostream>
using namespace std;

// unique_ptr �޸� ���� ���Ŀ� ��ü�� �ٽ� �����ϰ� �Ǹ�?
int main()
{
	int* arr = new int[10]; // ���� �Ҵ�
	unique_ptr<int> p1(arr);
	for (int i = 0; i < 10; i++) arr[i] = i;
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
	cout << endl;

	p1.reset(); // �޸� ����

	for (int i = 0; i < 10; i++) cout << arr[i] << ' '; // ������ �� ���
	cout << endl;
	return 0;
}