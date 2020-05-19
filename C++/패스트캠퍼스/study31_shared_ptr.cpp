#include <iostream>
using namespace std;

// shared_ptr

	/* �ϳ��� Ư���� ��ü�� �����ϴ� ����Ʈ �������� ������ �� �������� �����Ѵ�. 
	   
	   Ư���� ��ü�� ���ο� ����Ʈ �����Ͱ� ������ ������ ���� Ƚ��(Reference Count)�� 1�� �����ϸ�, �� ����Ʈ ��������
	   ������ ���� ������ 1�� �����Ѵ�. ��������� ���� Ƚ���� 0�� �Ǹ� delete Ű���带 �̿��� �޸𸮿��� �����͸� �ڵ�����
	   �Ҵ� �����Ѵ�. */

int main()
{
	int* arr = new int[10];
	arr[7] = 100;
	shared_ptr<int> p1(arr);
	cout << p1.use_count() << endl;
	shared_ptr<int> p2(p1);
	cout << p1.use_count() << endl;
	shared_ptr<int> p3 = p2;
	cout << p1.use_count() << endl;
	p1.reset();
	p2.reset();
	cout << "arr[7]: " << arr[7] << endl;
	p3.reset(); // ���� Ƚ���� 0�� �Ǹ� delete Ű���带 �̿��ؼ� �޸𸮿��� ����
	cout << p1.use_count() << endl;
	cout << "arr[7]: " << arr[7] << endl;
	return 0;
}