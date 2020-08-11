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
	SoDerived drv1(15); // base 생성자, derived 생성자, deirved 소멸자, base 소멸자
	SoDerived drv2(27);
	/*
	유도 클래스의 객체가 소멸될 때에는
	유도 클래스의 소멸자가 먼저 실행,
	그 다음에 기초 클래스의 소멸자가 실행
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