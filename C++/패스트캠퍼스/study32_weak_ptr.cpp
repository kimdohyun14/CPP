#include <iostream>
using namespace std;

// weak_ptr

	/* C++���� weak_ptr�� �ϳ� �̻��� shared_ptr ��ü�� �����ϰ� �ִ� ��ü�� ������ �� �ִ�.
	   ������ �ش� ��ü�� �������� ������ ���Ե��� �ʴ� ����Ʈ �������̴�.
	   
	   �Ϲ������� ���ΰ� ������ ����Ű�� �� ���� shared_ptr�� �ִٸ�, ���� Ƚ���� 0�� �� �� ���� ������
	   �޸𸮿��� ������ �� ����. weak_ptr�� �̷��� ��ȯ ����(Circular Reference) ������ �����ϱ� ���� �������� ����� �� �ִ�.*/

int main()
{
	int* arr = new int(1);
	shared_ptr<int> sp1(arr);
	weak_ptr<int> wp = sp1;
	cout << sp1.use_count() << endl;
	cout << wp.use_count() << endl;
	if (true)
	{
		shared_ptr<int> sp2 = wp.lock(); // shared_ptr ������ ��ȯ
		cout << sp1.use_count() << endl;
		cout << wp.use_count() << endl;
	}
	//������(Scope)�� ����Ƿ� sp2�� �����ȴ�.
	cout << sp1.use_count() << endl;
	cout << wp.use_count() << endl;
	return 0;
}