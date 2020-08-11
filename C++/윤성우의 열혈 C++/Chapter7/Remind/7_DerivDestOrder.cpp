#include <iostream>
using namespace std;

class SoBase
{
private:
	int baseNum;
public:
	SoBase(int n) :baseNum(n)
	{
		cout << "SoBase() : " << baseNum << endl;
	}
	~SoBase()
	{
		cout << "~SoBase() : " << baseNum << endl;
	}
};

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived(int n) : SoBase(n), derivNum(n)
	{
		cout << "SoDerived() : " << derivNum << endl;
	}
	~SoDerived()
	{
		cout << "~SoDerived() : " << derivNum << endl;
	}
};

int main()
{
	SoDerived drv1(15); // base ������, derived ������, deirved �Ҹ���, base �Ҹ���
	SoDerived drv2(27);
	/*
	���� Ŭ������ ��ü�� �Ҹ�� ������
	���� Ŭ������ �Ҹ��ڰ� ���� ����,
	�� ������ ���� Ŭ������ �Ҹ��ڰ� ����
	SoBase() : 15
	SoDerived() : 15
	SoBase() : 27
	SoDerived() : 27
	~SoDerived() : 27
	~SoBase() : 27
	~SoDerived() : 15
	~SoBase() : 15
	*/
	return 0;
}