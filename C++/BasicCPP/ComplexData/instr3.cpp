#include <iostream>
using namespace std;
/*
istream 클래스의 두 번째 멤버 함수는 get()

이 함수는 개행 문자를 읽어서 버리지 않고, 입력 큐에 그대로 남겨둔다.
=> getline()과의 차이점이다.

그래서 보통 개행 문자를 버리기 위해서
cin.get() 을 호출하기도 한다.
=> 개행 문자이든 아니면 다른 무엇이든 간에 무조건 문자 하나를 읽는다.

결합해서 사용하기도 한다.
cin.get(name, ArSize).get();
=> cin.getline(name, ArSize) 와 동일한 의미다.

# 함수 오버로딩
매개변수 리스트를 다르게 하여 같은 이름의 함수를 여러 번 만드는 것

getline() 은 사용하기 좀 더 편하고,
get()은 에러 체킹이 좀 더 쉽다.
*/

int main()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "이름 입력:\n";
	cin.get(name, ArSize).get(); // 문자열, 개행 문자를 읽는다.
	cout << "좋아하는 디저트 입력:\n";
	cin.get(dessert, ArSize).get();
	cout << "맛있는 " << dessert << " 디저트를 준비하겠습니다. " << name << "님!\n";
	return 0;
}