#include <iostream>
using namespace std;

struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	inflatable bouquet =
	{
		"sunflowers",
		0.20,
		12.49
	};

	inflatable choice;
	cout << "bouquet: " << bouquet.name << " for $" << bouquet.price << endl;

	choice = bouquet; // 한 구조체를 다른 구조체에 대입 (멤버별 대입)
	cout << "choice: " << choice.name << " for $" << choice.price << endl;
	return 0;
}