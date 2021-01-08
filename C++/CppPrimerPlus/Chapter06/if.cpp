// if.cpp -- if 구문
#include <iostream>
int main()
{
	using std::cin;
	using std::cout;
	char ch;
	int spaces = 0;
	int total = 0;
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == ' ')
			++spaces;
		++total;
		cin.get(ch);
	}
	cout << "이 문장의 총 문자 수는 " << total << "이고, ";
	cout << "그 중에서 빈칸은 " << spaces << "개입니다.\n";
	return 0;
}