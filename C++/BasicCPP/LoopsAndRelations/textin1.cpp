#include <iostream>
using namespace std;
int main()
{
	char ch;
	int count = 0;
	cout << "문자들을 입력, 끝내려면 #: ";
	cin >> ch;
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin >> ch;
	}
	cout << endl << count << " 문자를 읽었습니다.\n\n";

	// 입력에 있는 빈칸 문자들이 에코되지 않는다!
	// cin은 빈칸 문자, 개행 문자들을 무시하고 건너뛴다.
	// cin 입력은 버퍼를 이용한다!
	// 사용자가 입력한 문자들은 Enter 키를 누르기 전까지는 프로그램에 전달되지 않는다.(속도)
	// 일반적으로 I/O 작업은 무겁다.

	// 공백을 해결하는 방안
	char ch2;
	int count = 0;
	cout << "문자들을 입력, 끝내려면 #: ";
	cin.get(ch2);
	while (ch2 != '#')
	{
		cout << ch2;
		++count;
		cin.get(ch2);
	}
	cout << endl << count << " 문자를 읽었습니다.\n";
	return 0;
}