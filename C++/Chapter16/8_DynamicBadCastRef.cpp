#include <iostream>
using namespace std;

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
	SoSimple simObj;
	SoSimple& ref = simObj;

	// 참조형을 대상으로 dynamic_cast 연산을 진행할 경우 bad_cast 예외가 발생할 수 있다.
	// 또 참조형은 NULL을 반환할 수 없으므로 이러한 상황에서는 bad_cast 예외를 날려준다.
	try
	{
		SoComplex& comRef = dynamic_cast<SoComplex&>(ref);
		comRef.ShowSimpleInfo();
	}
	catch (bad_cast expt)
	{
		cout << expt.what() << endl;
	}
	return 0;
}