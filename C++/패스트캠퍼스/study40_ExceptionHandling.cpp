#include <iostream>
using namespace std;

// 예외

	/* 예외(Exception)란 프로그램이 동작하는 과정에서 발생하는 예상치 못한 오류(Error)를 의미한다.
	   C++에서는 발생할 가능성이 높은 오류에 대해서 예외 처리(Exception Handling)을 할 수 있도록 해준다.
	*/

// 예외 처리 구문

	/* C++은 Try - Catch 구문을 이용해서 예외 처리를 수행할 수 있도록 한다.
	
	   - try   : 특정한 코드 블록에서 예외가 발생할 수 있음을 명시
	   - catch : 발생한 예외에 대해서 핸들러가 특정한 내용을 처리한다.
	   - throw : try구문에서 발생한 오류를 전달한다.
	*/

int main()
{
	int a = 7, b = 0;
	try
	{
		if (b == 0)
		{
			throw "0으로 나눌 수 없습니다.";
		}
		cout << a / b << endl;
	}
	catch (const char* str)
	{
		cout << str << endl;
	}
	return 0;
}