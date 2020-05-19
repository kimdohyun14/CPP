#include <iostream>
using namespace std;

// C++의 스마트 포인터

	/* 스마트 포인터(Smart Pointer)는 프로그래머의 실수로 메모리 누수(Memory Leak)을 방어하기 위한 수단으로,
	   포인터처럼 동작하는 클래스 템플릿(Class Template)이다.
	   
	   기본적으로 힙 영역에 동적 할당된 메모리를 해제하기 위해서는 delete 키워드를 쓰면 된다.
	   스마트 포인터를 이용하면 메모리 누수를 더 효과적으로 방지할 수 있기 때문에 컴퓨터 시스템의 안정성을 높일 수 있다. 
	   
	   Java, C#은 가비지콜렉터가 존재해서 안쓰는 영역은 자동으로 회수해간다.*/


// 스마트 포인터

	/* unique_ptr : 하나의 스마트 포인터가 특정한 객체를 처리할 수 있도록 한다.
	   shared_ptr : 특정한 객체를 참조하는 스마트 포인터가 총 몇개인지를 참조한다.
	   weak_ptr   : 하나 이상의 shared_ptr 인스턴스가 소유하는 객체에 대한 접근을 제공한다. */

// unique_ptr
	/* C++에서 하나의 스마트 포인터만이 특정한 객체를 처리하도록 할 때 unique_ptr을 사용할 수 있다.
	   이러한 스마트 포인터는 특정한 객체의 소유권을 가지고 있을 때만 소멸자가 객체를 삭제할 수 있다.*/

int main()
{
	unique_ptr<int> p1(new int(10));
	unique_ptr<int> p2;
	cout << "스마트 포인터 1: " << p1 << endl;
	cout << "스마트 포인터 2: " << p2 << endl;
	cout << "--- 소유권 이전 ---" << endl;
	p2 = move(p1);
	cout << "스마트 포인터 1: " << p1 << endl;
	cout << "스마트 포인터 2: " << p2 << endl;
	cout << "--- 메모리 할당 해제 ---" << endl;
	p2.reset();
	cout << "스마트 포인터 1: " << p1 << endl;
	cout << "스마트 포인터 2: " << p2 << endl;

	// unique_ptr 객체에 접근하기.
	unique_ptr<int> p3(new int(10));
	cout << *p3 << endl; // 관리하고 있는 객체를 반환한다.
	return 0;
}