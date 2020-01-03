#include <iostream>
using namespace std;

// const static 멤버는 
class CountryArea
{
public:
	const static int RUSSIA = 1707540; // 선언과 동시에 초기화 가능
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SOUTH_KOREA = 9922;
};

int main()
{
	cout << "러시아 면적: " << CountryArea::RUSSIA << "km^2" << endl;
	cout << "케나다 면적: " << CountryArea::CANADA << "km^2" << endl;
	cout << "중국 면적: " << CountryArea::CHINA << "km^2" << endl;
	cout << "한국 면적: " << CountryArea::SOUTH_KOREA << "km^2" << endl;
	return 0;
}