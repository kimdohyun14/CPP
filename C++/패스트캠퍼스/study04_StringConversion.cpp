#include <iostream>
#include <string>
using namespace std;

// C++의 string은 다른 자료형으로의 변환이 간편하다.

int main()
{
	int i = 123;
	string s = to_string(i);
	cout << "정수 -> 문자열: " << s << endl;
	s = "456";
	i = stoi(s); // string to integer
	cout << "문자열 -> 정수: " << i << endl;
	return 0;
}