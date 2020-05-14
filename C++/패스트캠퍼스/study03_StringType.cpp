#include <iostream>
#include <string> // C++은 표준 문자열 자료형을 제공한다.
using namespace std;

// C++의 문자열 자료형

// C언어의 문자열 : char arr[SIZE];
// C++의   문자열 : string s;

int main()
{
	string input; // string이라는 하나의 클래스이기 때문에 size() 내장함수를 사용할 수 있다.
	cin >> input;
	for (int i = 0; i < input.size(); i++) cout << input[i] << '\n';

	// C++ ignore 입력 버퍼 비우기!
    /* cin을 통해 문자를 입력받을 경우 바로 변수에 값이 저장되는 것이 아닌 입력한 문자가 입력버퍼에 저장되고
       버퍼에 저장된 값을 읽어들여 변수에 저장한다.

       숫자를 입력받을 경우에는 바로 변수에 저장하기 때문에 버퍼가 필요없다. */

    /* cin.ignore(읽어들일 문자의 개수, 읽어들이면 종료할 문자)
	   입력버퍼에 있는 문자를 최대 첫 번째 인자로 지정한 수만큼 읽어들여 버리고,
	   그리고 두 번째 인자로 지정한 문자를 읽어들이면 그 문자를 마지막으로 읽어들여 버리고 함수가 종료된다. */
	
	//cin.ignore();             // 입력 버퍼 초기화 1
	while(getchar() != '\n') {} // 입력 버퍼 초기화 2


	// C++에서 공백을 포함하여 한 줄을 모두 문자열 형태로 입력 받고자 한다면 getline()을 쓰자.
	string input2;
	getline(cin, input2);
	for (int i = 0; i < input2.size(); i++) cout << input2[i] << '\n';
	cout << input2.size();
	return 0;
}