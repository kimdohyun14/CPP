#include <iostream>
#include <deque>
using namespace std;

// C++ STL ������ �����̳�

	/* 1. STL ������ �����̳� ���̺귯���� �ſ� Ȱ�뵵�� ���� �ڷᱸ���� �����Ѵ�.
	   2. ������ C�� �̿��ϸ� �����ϱ� ��ٷο��� �پ��� �ڷᱸ���� �ս��� �̿��� �� �ִ�.
	   3. ���� ���� ���Ǵ� ������ �����̳ʴ� ����(Vector)�� ��(Deque)�̴�. 

	  - vector
	  - deque
	  - list
	  - forward list(������ ����Ʈ)
	*/

// ��

	/* ���� �� ������ �����͸� �ְų� �� �� �ִ� �ڷᱸ���̴�.
	   
	   - push_front() : ���� �տ� ������ ����
	   - pop_front()  : ���� �տ��� ������ ����
	   - push_back()  : ���� �ڿ� ������ ����
	   - pop_back()   : ���� �ڿ��� ������ ����
	   - insert()     : ���� Ư�� ��ġ�� �����͸� ����
	*/

// 4 7
// 4 5 5 5 7
// 4 9 5 5 5 7
// 1
int main()
{
	deque<int> dq;
	dq.push_front(3);
	dq.push_back(7);
	dq.pop_front();
	dq.push_front(4);
	for (int i = 0; i < dq.size(); i++) cout << dq[i] << ' ';
	cout << endl;

	deque<int>::iterator iter = dq.begin();
	dq.insert(iter + 1, 3, 5);
	for (int i = 0; i < dq.size(); i++) cout << dq[i] << ' ';
	cout << endl;

	iter = dq.begin();
	dq.insert(iter + 1, 1, 9);
	for (int i = 0; i < dq.size(); i++) cout << dq[i] << ' ';
	cout << endl;
	
	dq.clear(); // ���� ����.
	cout << dq.empty() << endl;
	return 0;
}