#include <iostream>
using namespace std;

template<typename T1, typename T2>
class MySimple
{
public:
	void WhoAreYou()
	{
		cout << "Size of T1: " << sizeof(T1) << endl;
		cout << "Size of T2: " << sizeof(T2) << endl;
		cout << "<typename T1, typename T2>" << endl;
	}
};

// ��ü Ư��ȭ
template<>
class MySimple<int, double>
{
public:
	void WhoAreYou()
	{
		cout << "Size of int: " << sizeof(int) << endl;
		cout << "Size of double: " << sizeof(double) << endl;
		cout << "<int, double>" << endl;
	}
};

// �κ� Ư��ȭ
/*
template<typename T1>
class MySimple<T1, double> // T2�� double�� �κ� Ư��ȭ
{
public:
	void WhoAreYou()
	{
		cout << "Size of T1: " << sizeof(T1) << endl;
		cout << "Size of double: " << sizeof(double) << endl;
		cout << "<T1, double>" << endl;
	}
};
*/

int main()
{
	MySimple<char, double> obj1;
	obj1.WhoAreYou();

	MySimple<int, long long> obj2;
	obj2.WhoAreYou();

	// ��ü Ư��ȭ�� �κ� Ư��ȭ���� �켱�� �ȴ�.
	MySimple<int, double> obj3;
	obj3.WhoAreYou();
	return 0;
}
