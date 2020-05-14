#include <iostream>
using namespace std;

// dynamic_cast 연산자는 안정적인 형 변환을 보장한다.
// 그에 비해서 static_cast 연산자는 속도는 dynamic_cast보다 빠르지만 안전성을 보장하지 않는다.

// dynamic_cast 연산자는 컴파일 시간이 아닌 실행 시간에 안전성을 검사한다는 점. (그래서 느리다)

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
	SoSimple* simPtr = new SoSimple;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr); // NULL을 반환
	if (comPtr == NULL)
		cout << "형 변환 실패" << endl;
	else
		comPtr->ShowSimpleInfo();

	return 0;
}