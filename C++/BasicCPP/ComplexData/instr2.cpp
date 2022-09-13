#include <iostream>
using namespace std;

/*
istream 클래스의 cin은 그 클래스에 속한다.
여기서 getline 은 멤버함수.

# getline() 을 이용한 행 단위 입력
- Enter 키에 의해 전달되는 개행 문자를 입력의 끝으로 간주하여 한 행 전체를 읽는다!
- 첫 번째 매개변수 : 저장할 배열의 이름
- 두 번째 매개변수 : 입력받을 문자들의 한계(길이), 최대 길이-1만큼만 받는다. 하나는 널 문자를 위해서
- 세 번째 매개변수 : 특정 단어에서 끝내기 위해서 사용하는 변수

- 개행 문자는 저장하지 않는다.
- 문자열을 배열에 저장할 때 개행 문자는 널 문자로 대체된다.
- 편리하게 한 행을 한 번에 읽는다.
*/

int main()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "이름 입력:\n";
	cin.getline(name, ArSize); // 개행 문자가 있는 곳까지 읽는다.
	cout << "좋아하는 디저트 입력:\n";
	cin.getline(dessert, ArSize); 
	cout << "맛있는 " << dessert << " 디저트를 준비하겠습니다. " << name << "님!\n";
	return 0;
}