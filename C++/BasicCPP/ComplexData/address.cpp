#include <iostream>
using namespace std;

int main()
{
	int donuts = 6;
	double cups = 4.5;

	// �ּ� ������ &�� ���� �տ� ���̸� �� ������ �ּҸ� �� �� �ִ�.
	cout << "donuts�� �� = " << donuts;
	cout << ", donuts�� �ּ� = " << &donuts << endl;

	cout << "cups�� �� = " << cups;
	cout << ", cups�� �ּ� = " << &cups << endl;
	return 0;
}