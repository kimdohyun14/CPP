#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s1 = "penguin";
	string s2, s3;

	// C배열은 안됨.
	cout << "string 객체를 string 객체에 대입할 수 있다\n";
	s2 = s1;
	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;
	cout << "string 객체에 C 스타일 문자열을 대입할 수 있다\n";
	cout << "s2 = \"buzzard\"\n";
	s2 = "buzzard";
	cout << "s2 : " << s2 << endl;

	s3 = s1 + s2;
	cout << "s3 : " << s3 << endl;

	s1 += s2;
	cout << "s1 : " << s1 << endl;
	s2 += " for a day";
	cout << "s2 : " << s2 << endl;
	return 0;
}