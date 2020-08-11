#include <iostream>
using namespace std;

// 유도 클래스의 객체 생성과정에 대해서 자세히 보자.
class SoBase
{
private:
	int baseNum;
public:
	SoBase() : baseNum(20)
	{
		cout << "SoBase()" << endl;
	}
	SoBase(int n) : baseNum(n)
	{
		cout << "SoBase(int n)" << endl;
	}
	void ShowBaseData() const
	{
		cout << baseNum << endl;
	}
};  //클래스는 항상 마지막에 세미콜론을 붙여준다.

class SoDerived : public SoBase
{
private:
	int derivNum;
public:
	SoDerived() : derivNum(30)
	{
		cout << "SoDerived()" << endl;
	}
	SoDerived(int n) : derivNum(n)
	{
		cout << "SoDerived(int n)" << endl;
	}
	SoDerived(int n1, int n2) : SoBase(n1), derivNum(n2)
	{
		cout << "SoDervied(int n1, int n2)" << endl;
	}
	void ShowDerivData() const
	{
		ShowBaseData();
		cout << derivNum << endl;
	}
};

int main()
{
	// 항상 유도 클래스는 기초 클래스의 생성자가 먼저, 그 다음에 유도 클래스의 생성자가 된다.
	cout << "case1....." << endl;
	SoDerived dr1;
	dr1.ShowDerivData();
	cout << "-------------------------" << endl;
	cout << "case2....." << endl;
	SoDerived dr2(12);
	dr2.ShowDerivData();
	cout << "-------------------------" << endl;
	cout << "case3....." << endl;
	SoDerived dr3(23, 24);
	dr3.ShowDerivData();
	return 0;
}