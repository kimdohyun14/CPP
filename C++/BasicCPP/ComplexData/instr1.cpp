#include <iostream>
using namespace std;
int main()
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "이름 입력:\n";
	cin >> name;
	cout << "좋아하는 디저트 입력:\n";
	cin >> dessert;
	cout << "맛있는 " << dessert << " 디저트를 준비하겠습니다. " << name << "님!\n";
	return 0;
}

// cin은 문자열의 끝을 인식하는 방법을 사용하여, 위의 구문은 이상하게 출력된다.
// 키보드로는 널 문자를 입력할 수 없기 때문!
// cin은 빈칸, 탭, 캐리지 리턴과 같은 '화이트스페이스'가 있다면 그 위치에서 문자열이 끝난 것으로 간주한다.
// => 그래서 하나의 단어만 읽어 그것을 배열에 저장하고 널 문자를 끝에 추가 하게 된다.

/*
입력 : Alistair Dreeb

- 첫번째 문자열 Alistair 는 name 배열에 저장된다.
- Dreeb은 입력 큐에 그대로 남겨 놓는다.
- 좋아하는 디저트에 대한 응답을 얻기 위해 cin이 다시 입력 큐를 검사할 때,
- 그때까지 입력 큐에 남아있던 Dreeb을 두 번째 문자열로 읽어 dessert 배열에 저장한다.

즉 name에는 "Alistair\0"
dessert에는 "Dreeb\0"
이 들어가게 된다.
*/