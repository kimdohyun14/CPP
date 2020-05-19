#include <iostream>
using namespace std;

// weak_ptr

	/* C++에서 weak_ptr은 하나 이상의 shared_ptr 객체가 참조하고 있는 객체에 접근할 수 있다.
	   하지만 해당 객체의 소유자의 수에는 포함되지 않는 스마트 포인터이다.
	   
	   일반적으로 서로가 상대방을 가리키는 두 개의 shared_ptr이 있다면, 참조 횟수는 0이 될 수 없기 때문에
	   메모리에서 해제될 수 없다. weak_ptr은 이러한 순환 참조(Circular Reference) 현상을 제거하기 위한 목적으로 사용할 수 있다.*/

int main()
{
	int* arr = new int(1);
	shared_ptr<int> sp1(arr);
	weak_ptr<int> wp = sp1;
	cout << sp1.use_count() << endl;
	cout << wp.use_count() << endl;
	if (true)
	{
		shared_ptr<int> sp2 = wp.lock(); // shared_ptr 포인터 반환
		cout << sp1.use_count() << endl;
		cout << wp.use_count() << endl;
	}
	//스코프(Scope)를 벗어나므로 sp2가 해제된다.
	cout << sp1.use_count() << endl;
	cout << wp.use_count() << endl;
	return 0;
}