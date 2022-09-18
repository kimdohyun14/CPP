#include <iostream>
#include <string>
using namespace std;

// C 스타일 문자열로 string 객체를 초기화 가능
// cin 을 사용하여 string 객체에 키보드 입력을 저장가능
// cout 을 사용해서 string 객체를 볼 수 있다.
// 배열 표기를 사용해서 string 객체에 저장되어 있는 개별적인 문자들에 접근 및 쓰기가 가능하다.
int main()
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther"; 

	cout << "고양이과의 동물 한 종을 입력 : ";
	cin >> charr1;
	cout << "고양이과의 또 다른 동물 한 종을 입력 : ";
	cin >> str1; // str1의 크기를 자동으로 조절한다. (입력에 맞게 크기가 조절된다.)
	cout << "아래 동물들은 모두 고양이과입니다:\n";
	cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;

	cout << charr2 << "에서 세 번째 글자 : " << charr2[2] << endl;
	cout << str2 << "에서 세 번째 글자 : " << str2[2] << endl;
	return 0;
}