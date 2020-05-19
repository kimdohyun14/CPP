#include <iostream>
using namespace std;

// ����� Ư��ȭ

	/* C++�� �Լ� ���ø��� Ư���� Ÿ�Կ� ���Ͽ� ����� Ư��ȭ(Explicit Specialization) ����� �����Ѵ�.
	   �̷��� ����� Ư��ȭ�� �̿��ϸ� Ư���� Ÿ�Կ� ���ؼ� Ư���� ����� ������ �� �ִ�. 
	   
	   �����Ϸ��� ȣ��� �Լ��� �����ϴ� Ư��ȭ�� ���Ǹ� �߰��� ���Ŀ��� �ش� ���Ǹ��� ����Ѵ�. */

template<typename T>
void change(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

// ����� Ư��ȭ
template<>
void change<int>(int& a, int& b)
{
	cout << "������ �����͸� ��ü�Ѵ�." << endl;
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	string a = "dohyun";
	string b = "hello";
	change(a, b);
	cout << a << " : " << b << endl;

	int n1 = 5;
	int n2 = 7;
	change(n1, n2);
	cout << n1 << " : " << n2 << endl;
	return 0;
}