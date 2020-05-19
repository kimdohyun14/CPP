#include <iostream>
using namespace std;

// 명시적 특수화

	/* C++의 함수 템플릿은 특정한 타입에 대하여 명시적 특수화(Explicit Specialization) 기능을 제공한다.
	   이러한 명시적 특수화를 이용하면 특정한 타입에 대해서 특수한 기능을 정의할 수 있다. 
	   
	   컴파일러는 호출된 함수에 대응하는 특수화된 정의를 발견한 이후에는 해당 정의만을 사용한다. */

template<typename T>
void change(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

// 명시적 특수화
template<>
void change<int>(int& a, int& b)
{
	cout << "정수형 데이터를 교체한다." << endl;
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