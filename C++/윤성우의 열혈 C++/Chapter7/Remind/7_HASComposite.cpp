#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum)
	{}
	void Shot()
	{
		cout << "BBANG!!!" << endl;
		--bullet;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;    // 소유하고 있는 권총(이렇게 표현하기도 HAS-A)
public:
	Police(int bnum, int bcuff)
		:handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	void PutHandcuff()
	{
		cout << "SNAP!!!" << endl;
		--handcuffs;
	}

	// 상속하고 있지 않기 때문에 쏘는 함수를 만들어야 한다.
	void Shot()
	{
		if (pistol == NULL)
			cout << "Hut BBANG!!" << endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main()
{
	Police pman1(5, 3);
	pman1.Shot();
	pman1.PutHandcuff();

	Police pman2(0, 3);
	pman2.Shot();
	pman2.PutHandcuff();
	return 0;
}