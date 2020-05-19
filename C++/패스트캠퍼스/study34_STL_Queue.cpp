#include <iostream>
#include <queue>
using namespace std;

// C++ STL 컨테이너 어댑터 : 큐

	/* - 추가: push(원소)
	   - 삭제: pop()
	   - 조회: front() / back() 
	   - 검사: empty() / size()
	*/

int main()
{
	queue<int> q;
	q.push(7);
	q.push(5);
	q.push(4);
	q.pop();
	q.push(6);
	q.pop();
	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}