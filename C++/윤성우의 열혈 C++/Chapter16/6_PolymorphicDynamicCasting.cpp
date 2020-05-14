#include <iostream>
using namespace std;

// Polymorphic class는 하나 이상의 가상함수를 지니는 클래스를 뜻한다.
// 해당 클래스가 Polymorphic class이면 dynamic_cast 연산자를 활용해서 기초 클래스 -> 유도 클래스로 형 변환이 가능하다.

class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		cout << "SoSimple Base Class" << endl;
	}
};

class SoComplex : public SoSimple
{
public:
	void ShowSimpleInfo()
	{
		cout << "SoComplex Derived Class" << endl;
	}
};

int main()
{
	SoSimple* simPtr = new SoComplex;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();
	return 0;
}