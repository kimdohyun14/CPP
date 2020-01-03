#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{}
	void Shot()
	{
		cout << "BBANG!!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bnuff)
		:handcuffs(bnuff)
	{
		if (bnum > 0)
		{
			pistol = new Gun(bnum);
		}
		else
		{
			pistol = NULL;
		}
	}
	void PutHandCuff()
	{
		cout << "SNAP!!" << endl;
	}

	void Shot()
	{
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
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
	pman1.PutHandCuff();

	Police pman2(0, 3);
	pman2.Shot();
	pman2.PutHandCuff();
	return 0;
}