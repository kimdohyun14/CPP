#include <iostream>
using namespace std;

// 이러한 catch 블록을 구성하면 안된다.

class AAA
{
public:
	void ShowYou() { cout << "AAA exception!" << endl; }
};

class BBB : public AAA
{
public:
	void ShowYou() { cout << "BBB exception!" << endl; }
};

class CCC : public BBB
{
public:
	void ShowYou() { cout << "CCC exception!" << endl; }
};

void ExceptionGenerator(int expn)
{
	if (expn == 1)
		throw AAA();
	else if (expn == 2)
		throw BBB();
	else
		throw CCC();
}

int main()
{
	try
	{
		ExceptionGenerator(3);
		ExceptionGenerator(2);
		ExceptionGenerator(1);
	}
	catch (CCC & expn)
	{
		cout << "catch(CCC& expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB & expn)
	{
		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (AAA & expn)
	{
		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
	/* 
	catch (AAA & expn)
	{
		cout << "catch(AAA& expn)" << endl;
		expn.ShowYou();
	}
	catch (BBB & expn)
	{
		cout << "catch(BBB& expn)" << endl;
		expn.ShowYou();
	}
	catch (CCC & expn)
	{
		cout << "catch(CCC& expn)" << endl;
		expn.ShowYou();
	}
	*/
	return 0;
}