#include <iostream>
using namespace std;
int main()
{
	int nights = 1001;
	int* pt = new int; // int형을 저장할 메모리를 대입
	*pt = 1001;

	cout << "nights : " << nights << ": 메모리 위치 = " << &nights << endl;
	cout << "int 형 값 = " << *pt << ": 메모리 위치 = " << pt << endl;

	double* pd = new double;
	// new double : double형 데이터를 저장할 새로운 메모리가 필요하다고 알린다.
	// 적당한 메모리를 찾아 필요한 만큼 블록을 대입하고, 그 주소를 리턴한다.
	*pd = 10000001.0;

	cout << "double 형";
	cout << " 값 = " << *pd << ": 메모리 위치 = " << pd << endl;
	cout << "포인터 pd의 메모리 위치: " << &pd << endl << endl;
	cout << "pt의 크기 = " << sizeof pt << endl; // 주의깊게 보자
	cout << "*pt의 크기 = " << sizeof(*pt) << endl;
	cout << "pd의 크기 = " << sizeof pd << endl; // 주의깊게 보자
	cout << "*pd의 크기 = " << sizeof(*pd) << endl;

	// 본질적으로 주소는 저장된 어떤 데이터 객체의 시작 주소만 알려 줄뿐,
	// 그 객체의 데이터형이나 바이트 수는 알려주지 않는다!!

	// 그래서 int형을 지시하는 포인터의 크기와
	// double형을 지시하는 포인터의 크기가 같다.
	// 둘 다 단순한 주소일 뿐이기 때문이다.
	return 0;
}

/* delete를 사용한 메모리 해제!

- 사용한 메모리를 다시 메모리 풀로 회수하는 키워드가 delete 연산자다.
- 이렇게 해제한 메모리는 프로그램의 다른 부분이 다시 사용할 수 있게 된다.
- new 사용한 후에는 반드시 나중에 delete 를 사용해야한다.
- 그렇지 않게 되면 메모리 누수(메모리 릭)이 발생한다.
- 메모리 누수의 규모가 너무 커지면 메모리를 많이 요구하는 포로그램이 먹통이 될 수 있다.
- 이미 해제한 메모리 블록을 다시 해제하려고 시도하면 절대 안 된다!

- new로 대입한 메모리에만 delete를 사용하자!
- 동일한 주소에 사용해야 한다는 뜻이다!
- 아래와 같은 상황은 OK
- 다만 같은 메모리 블록을 지시하는 두 개의 포인터를 만드는 것은 실수를 유발하지만,
- 포인터를 리턴하는 함수에서는 두 번째 포인터를 사용할 수 있다.
int * ps = new int;
int * pq = ps;
delete pq;



*/