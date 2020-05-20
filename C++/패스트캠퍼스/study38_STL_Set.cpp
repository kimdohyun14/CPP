#include <iostream>
#include <set>
using namespace std;

// C++ STL ���� �����̳�

	/* 1. STL ���� �����̳� ���̺귯���� �ſ� Ȱ�뵵�� ���� �ڷᱸ���� �����Ѵ�.
	   2. ���� �����̳ʴ� Ű(Key)�� ��(Value)������ ���� �ִ� �����͸� ������ �����ϴ� �����̳�.
	   3. ���� ���� ���Ǵ� ������ �����̳ʴ� ����(Set)�� ��(Map)
	   
	   - set(����)
	   - multiset(��Ƽ ����)
	   - map(��)
	   - multimap(��Ƽ ��)
	*/

// set

	/* ������ �����ϴ� �����͸� Ű(Key)�� ����ϴ� ���� �����̳��̴�.
	   ���ĵ� ��ġ�� �����͸� �����Ѵٴ� ������ �˻� �ӵ��� �����ٴ� Ư¡�� �ִ�.
	   �⺻������ Ű�� �ߺ��� ������� �ʴ´�.
	*/

// 2 4 6 8 10
// 1 2 3 4 5 6 8 10
int main()
{
	int arr[5] = { 2,4,6,8,10 };
	set<int> s(arr, arr + 5);
	set<int>::iterator iter = s.begin();
	for (iter = s.begin(); iter != s.end(); iter++) cout << *iter << ' ';
	cout << endl;

	s.insert(1);
	s.insert(3);
	s.insert(5);
	for (iter = s.begin(); iter != s.end(); iter++) cout << *iter << ' ';
	cout << endl;
	return 0;
}