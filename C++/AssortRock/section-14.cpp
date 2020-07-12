#include <iostream>
using namespace std;

struct _tagStudent
{
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	/*
	포인터 : 가리키다. 일반 변수는 일반적인 값을 저장하게 되지만,
	포인터 변수는 메모리 주소를 저장하게 된다. 모든 변수 타입은 포인터 타입을 선언할 수 있다.
	int변수의 주소는 int 포인터 변수에 저장을 해야한다. (타입을 지키지 않으면 원활한 데이터가 출력되지 않을 수 있다.)
	포인터는 메모리 주소를 담아놓는 변수이기 때문에 x86으로 개발할 때는 무조건 4byte가 나온다.
	x64일 때는 8byte가 나온다.

	포인터는 자기 스스로 아무런일도 할 수 없다. 반드시 다른 변수의 메모리 주소를 가지고 있어야 일을 할 수 있는데,
	가지고 있는 그 메모리 주소에 접근해서 값을 제어할 수 있다.
	
	형태 : 변수타입 *변수명;
	*/
	int iNumber = 100;
	// 변수 선언시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다.
	// 변수 앞에 &을 붙여주면 해당 변수의 메모리 주소가 된다.
	// pNum은 iNumber 변수의 메모리 주소를 값으로 갖게 된다.
	// 그러므로 pNum을 이용해서 iNumber의 값을 제어할 수 있게 된다.
	int* pNum = &iNumber;

	// x86 => 모두 4바이트, x64 => 모두 8바이트
	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	// pNum을 이용해서 iNumber의 값을 제어해보자.
	// 역참조를 이용해서 값을 얻어오거나 변경할 수 있다.
	// 역참조는 포인터 변수 앞에 *을 붙이게 되면 역참조가 된다.
	cout << *pNum << endl;
	*pNum = 1234;

	cout << "iNumber Address : " << iNumber << endl;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	// 포인터 변수도 변수이기 때문에 주소를 가지고 있다.
	cout << "pNum Address : " << &pNum << endl;

	/*
	포인터와 배열의 관계 : 배열명은 포인터이다. 배열명 자체가 해당 배열의 메모리에서의 시작점 주소를 의미한다.
	*/
	int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "Array Address : " << iArray << endl;
	cout << "Array Address : " << &iArray[0] << endl;

	int* pArray = iArray;

	cout << pArray[2] << endl;

	/*
	포인터 연산 : +, - 연산을 제공한다. ++, -- 도 가능한데 1을 증가하게 되면
	단순히 메모리 주소값이 1 증가하는 것이 아니라, int 포인터의 경우 int 타입의 메모리 주소를 갖게 되는데
	메모리 주소에 1을 더해주면 1증가가 아닌 해당 포인터타입의 변수타입 크기만큼 증가하게 된다.
	int 포인터이므로 int의 크기인 4만큼 값이 증가하게 되는 것이다.
	*/

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl; // 연산자 우선순위 때문에, 역참조를 먼저하고 난뒤, 100을 더해서 결과가 101이 된다.

	// 상수 문자열 (const) 바꿀 수 없는 문자열이다.
	// 이 문자열을 저장할 수 있을 만큼의 크기를 만든 다음에, 이 상수 문자열을 저장할 수 있는 배열이 잡히고,
	// 그 녀석의 메모리 주소를 반환해준다.
	const char* pText = "테스트 문자열"; 
	// 바꿀 수 없는 문자열에 바꿀려고 하면 안된다.
	// pText[0] = 'a'; 

	// 문자열 출력
	cout << pText << endl;
	// 문자열 주소
	cout << (int*)pText << endl;

	// 가리키는 주소를 변경할 수 있게 된다.
	pText = "abcde";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// 똑같이 다시 가리키게 해도, 가리키는 주소는 동일하게 된다.
	pText = "abcde";
	cout << pText << endl;
	cout << (int*)pText << endl;

	// 문자열을 변경할 수 있는 문자열
	char str[8] = "abcdefg";

	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	_tagStudent tStudent = {};

	tStudent.iKor = 100;
	cout << tStudent.iKor << endl;

	// 구조체 포인터
	_tagStudent* pStudent = &tStudent;

	// 연산자 우선순위 때문에 .을 먼저 인식하게 된다.메모리주소 .은 잘못된 문법이다. 
	// 그러므로 소괄호로 감싸준 후에 .을 이용해서 가리키는 대상의 멤버변수에 접근해야 한다.
	(*pStudent).iKor = 50;
	cout << tStudent.iKor << endl;

	// 위와 같은 방법이지만 다음과 같이 사용할 수 있다.
	// 메모리주소 -> 을 이용해서 가키리는 대상의 멤버에 접근할 수 있다. (간단 명료)
	pStudent->iKor = 80;
	cout << tStudent.iKor << endl;

	// void : 타입이 없다. void의 포인터타입을 활용할 수 있다.
	// void* 변수를 선언하게 되면 이 변수는 어떤 타입의 메모리 주소든 모두 저장가능하다.
	// 단, 역참조가 불가능하고 메모리 주소만 저장 가능하다.
	// 일종의 메모리 주소만 저장하기 위한 버퍼로 사용할 수 있다.
	void* pVoid = &iNumber;
	cout << "iNumber Address : " << &iNumber << endl;
	cout << "iNumber Address : " << pVoid << endl;

	// 형변환을 통해서 주소값을 넣은 다음에 사용한다.
	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	cout << "iNumber : " << iNumber << endl;
	// 이렇게도 사용이 가능하다.
	*((int*)pVoid) = 9999;
	cout << "iNumber : " << iNumber << endl;

	// 구조체 역시 형변환을 통해서 주소값을 넣은 다음에 사용이 가능하다.
	pVoid = &tStudent;
	cout << "tStudent Address : " << &tStudent << endl;
	cout << "tStudent Address : " << pVoid << endl << endl;

	int iNum1 = 1000;
	int iNum2 = 2000;
	pNum = &iNum1;
	// 이중 포인터 : *을 2개 붙인다.
	// 일반 포인터 변수가 일반 변수의 메모리 주소를 저장하는 변수라면
	// 이중 포인터는 포인터의 포인터이다. 즉, 이중 포인터는 포인터 변수의 메모리 주소를 저장하는 포인터이다.
	int** ppNum = &pNum;

	*ppNum = &iNum2; // pNum의 value를 iNum2의 주소값으로 바꾼다. (변경한다.)
	*pNum = 3000;

	cout << "iNum1 : " << iNum1 << endl;
	cout << "iNum1 Addr : " << &iNum1 << endl;
	cout << "iNum2 : " << iNum2 << endl;
	cout << "iNum2 Addr : " << &iNum2 << endl << endl;

	cout << "*pNum : " << *pNum << endl;
	cout << "pNum Value : " << pNum << endl; // 가리키고 있는 변수의 주소값
	cout << "pNum Addr : " << &pNum << endl << endl;

	cout << "**ppNum : " << **ppNum << endl;
	cout << "*ppNum : " << *ppNum << endl;     // pNum의 value
	cout << "ppNum Value : " << ppNum << endl; // &pNum
	cout << "ppNum Addr : " << &ppNum << endl;
	return 0;
}