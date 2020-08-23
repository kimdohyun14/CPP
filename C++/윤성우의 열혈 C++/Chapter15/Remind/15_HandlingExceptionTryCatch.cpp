#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "µÎ °³ÀÇ ¼ıÀÚ ÀÔ·Â: ";
	cin >> num1 >> num2;

	try
	{
		if (num2 == 0)
			throw num2;

		cout << "³ª´°¼ÀÀÇ ¸ò: " << num1 / num2 << endl;
		cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö: " << num1 % num2 << endl;
	}

	catch (int expn)
	{
		cout << "Á¦¼ö´Â " << expn << "ÀÌ µÉ ¼ö ¾ø´Ù." << endl;
	}

	cout << "end of main" << endl;
	return 0;
}