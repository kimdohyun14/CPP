#include <iostream>
#include <stack>
using namespace std;

// C++ STL �����̳� �����

	/* 1. STL�����̳� ����� ���̺귯���� �ſ� Ȱ�뵵�� ���� �ڷᱸ���� �����Ѵ�. 
	   2. ������ C�� �̿��ϸ� �����ϱ� ��ٷο��� �پ��� �ڷᱸ���� �ս��� �̿��� �� �ִ�. 
	   
	   - Stack(����)
	   - Queue(ť)
	   - PriorityQueue(�켱���� ť)
	*/

// Stack

	/* C++ Stack STL�� ������ ���� �Լ��� �����Ǿ� �ִ�.
	
	   - �߰�: push(����)
	   - ����: pop()
	   - ��ȸ: top()
	   - �˻�: empty() / size() 
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