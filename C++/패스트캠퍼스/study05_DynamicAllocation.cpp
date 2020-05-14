#include <iostream>
#define SIZE 100
using namespace std;

/* C++는 객제 지향 패러다임을 따르고 있는 언어이지만 C언어는 절차적 프로그래밍 언어.
   C++은 객체 중심의 언어이며 C언어는 함수 기반의 언어
   C++은 C언어의 구조체(struct) 대신에 클래스(Class)를 사용
   C++은 공식적으로 예외 처리(Exception Handling) 기술을 지원한다.*/

int* arr;

int main()
{
	arr = new int[SIZE]; // 동적할당
	for (int i = 0; i < SIZE; i++) arr[i] = i;
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << ' ';
	}
	delete arr; // 할당 해제
	return 0;
}