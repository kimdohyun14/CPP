#include <iostream>
using namespace std;
int main()
{
	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3, 2, 1 };

	// 배열의 주소를 알아내는 두 가지 방법
	double* pw = wages;
	short* ps = &stacks[0];

	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1; // 포인터 연산!
	             // 값이 그 포인터가 지시하는 데이터형의 바이트 수만큼 증가한다.
	             // C++ 배열 이름을 주소로 해석한다는 사실이 중요하다.
	cout << "pw 포인터에 1을 더하면? \n";
	cout << "pw = " << pw << ", *pw = " << *pw << endl << endl;

	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "ps 포인터에 1을 더하면? \n";
	cout << "ps = " << ps << ", *ps = " << *ps << endl << endl;

	cout << "배열 표기로 두 원소에 접근\n";
	cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;

	cout << "포인터 표기로 두 원소에 접근\n";
	cout << "*stacks = " << *stacks << ", *(stacks + 1) = " << *(stacks + 1) << endl;

	// 배열 이름에 sizeof 연산자 적용시 : 배열의 크기를 얻을 수 있지만,
	// 포인터 이름에 sizeof 연산자 적용시 : 그 포인터가 배열을 지시하고 있더라도, 포인터의 크기가 리턴된다.
	cout << sizeof wages << " = wages 배열의 크기\n";
	cout << sizeof pw << " = pw 포인터의 크기\n";

	// 배열 이름은 값을 변경할 수 없는 상수인 반면에
	// 포인터 이름은 값을 변경할 수 있는 변수라는 사실!

	// 주의
	// 배열의 주소를 얻는 것은 배열의 이름을 얻는 것과는 다른 얘기
	// 배열의 이름은 배열의 첫 번째 원소의 주소를 가리킨다.
	// 반면에, 주소 연산자를 적용하면 전체 배열의 주소가 산출된다.
	short tell[10];
	cout << tell << ", " << sizeof tell << endl;    // &tell[0]을 출력
	cout << &tell << ", " << sizeof(&tell) << endl; // 전체 배열의 주소를 출력

	// tell과 &tell[0]은 2바이트 메모리 블록으로 동일한 값을 갖는다.
	// &tell은 20바이트 메모리 블록의 주소이다.

	short (*pas)[10] = &tell; // pas는 10바이트 배열을 가리킨다.
							  // *pas 는 tell과 동일
	                          // (*pas)[0] 은 tell 배열의 첫 번째 원소가 된다.
	return 0;
 }