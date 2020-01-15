#include <iostream>
using namespace std;

// Polymorphic class�� �ϳ� �̻��� �����Լ��� ���ϴ� Ŭ������ ���Ѵ�.
// �ش� Ŭ������ Polymorphic class�̸� dynamic_cast �����ڸ� Ȱ���ؼ� ���� Ŭ���� -> ���� Ŭ������ �� ��ȯ�� �����ϴ�.

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