#include <iostream>
using namespace std;

// C++의 템플릿

	/* C++은 일반화 프로그래밍(Generic Programming)이 가능한 언어이다.
	   템플릿(Template)을 이용해서 일반화 프로그래밍을 사용할 수 있다. */

// 템플릿

	/* 템플릿이란 매개변수의 타입에 따라서 함수 및 클래스를 손쉽게 사용할 수 있도록 해준다.

	   템플릿은 그 타입 자체가 매개변수에 의해서 다루어 진다. 따라서 템플릿을 사용하면 타입마다 별도의 함수나
	   클래스를 만들지 않고, 다양한 타입에서 동작할 수 있는 단 하나의 객체를 정의할 수 있다. 결과적으로 소스코드의
	   재사용성을 극대화할 수 있는 객체 지향 프로그래밍 기법 중 하나이다. */

// 함수 템플릿

	/* 함수 템플릿(Function Template)이 각각의 자료형에 대해서 처음으로 호출이 될 때, C++ 컴파일러는 해당 타입의
	   인스턴스를 생성하게 된다. 이후에 생성된 하나의 인스턴스는 해당 자료형에 대해서 특수화가 이루어진다. 이러한
	   인스턴스는 해당 함수 템플릿에 해당 자료형이 사용될 때마다 호출된다. */

template<typename T>
void change(T& a, T& b)
{
	T temp;
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
	return 0;
}