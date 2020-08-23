#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	cout << "µÎ °³ÀÇ ¼ıÀÚ ÀÔ·Â: ";
	cin >> num1 >> num2;

	if (num2 == 0)
	{
		cout << "Á¦¼ö´Â 0ÀÌ µÉ ¼ö ¾ø´Ù." << endl;
	}

	else
	{
		cout << "³ª´°¼ÀÀÇ ¸ò: " << num1 / num2 << endl;
		cout << "³ª´°¼ÀÀÇ ³ª¸ÓÁö: " << num1 % num2 << endl;
	}

	return 0;
}