#include <iostream>
#include <stack>
using namespace std;

// C++ STL 컨테이너 어댑터

	/* 1. STL컨테이너 어댑터 라이브러리는 매우 활용도가 높은 자료구조를 제공한다. 
	   2. 기존의 C언어를 이용하면 구현하기 까다로웠던 다양한 자료구조를 손쉽게 이용할 수 있다. 
	   
	   - Stack(스택)
	   - Queue(큐)
	   - PriorityQueue(우선순위 큐)
	*/

// Stack

	/* C++ Stack STL은 다음과 같은 함수로 구성되어 있다.
	
	   - 추가: push(원소)
	   - 삭제: pop()
	   - 조회: top()
	   - 검사: empty() / size() 
	*/

int main()
{
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(4);
	s.pop();
	s.push(6);
	s.pop();
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}