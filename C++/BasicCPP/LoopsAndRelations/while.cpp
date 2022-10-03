#include <iostream>
using namespace std;

const int ArSize = 20;
int main()
{
	char name[ArSize];

	cout << "영문 입력 : ";
	cin >> name;
	cout << "귀하의 영문 이름을 한 줄에 한 자씩\n";
	cout << "ASCII 코드와 함께 표시하면 이렇다.\n";
	int i = 0;
	while (name[i] != '\0')
	{
		cout << name[i] << ": " << int(name[i]) << endl;
		i++;
	}
	// C 스타일 문자열과 달리, string 클래스에서는 
	// 문자열의 끝을 인식하기 위하여 널 문자를 사용하지 않는다는 장점이 있다.

	return 0;
}