#include <iostream>
using namespace std;

// dynamic_cast �����ڴ� �������� �� ��ȯ�� �����Ѵ�.
// �׿� ���ؼ� static_cast �����ڴ� �ӵ��� dynamic_cast���� �������� �������� �������� �ʴ´�.

// dynamic_cast �����ڴ� ������ �ð��� �ƴ� ���� �ð��� �������� �˻��Ѵٴ� ��. (�׷��� ������)

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
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr); // NULL�� ��ȯ
	if (comPtr == NULL)
		cout << "�� ��ȯ ����" << endl;
	else
		comPtr->ShowSimpleInfo();

	return 0;
}