#include <iostream>
using namespace std;

// cin은 EOF를 탐지했을 때, 두 개의 비트 eofbit, failbit를 1로 설정한다.
// cin.eof()의 호출은 EOF가 탐지되었으면 true, 아니면 false
// cin.fail()의 호출은 eofbit 또는 failbit가 1로 설정되어 있으면 true, 아니면 false
// 두 메서드 모두 미래를 예측하는 것이 아니라 과거를 보고한다.

// 플래그가 설정되면, cin은 더 이상의 입력을 받아들이지 않는다.
// cin.clear() 메서드는 EOF 플래그를 지우고, 다시 입력이 진행될 수 있도록 허용한다.

// cin.get(char) 메서드가 리턴하는 값은 cin 객체
// istream 클래스는 cin과 같은 istream 객체를 bool 값으로 변환하는 함수를 제공한다.
// bool값으로 변환된 결과는 마지막으로 시도한 읽기가 성공이면 true, 실패면 false 리턴한다.

int main()
{
	char ch;
	int count = 0;
	cin.get(ch); // 문자 하나 읽기
	while (cin.fail() == false)  // EOF 검사, while (cin.get(ch)) 이것도 가능하다.
                                 // 입력이 성공적이면 ch에 값을 넣는다.
		                         // 종료 조건을 파악, 조건을 초기화, 조건을 갱신(3가지 처리)
	{
		cout << ch; // 문자 에코
		++count;
		cin.get(ch); // 다음 문자를 읽는다.
	}

	cout << count << " 문자를 읽었습니다.\n";
	return 0;
}
