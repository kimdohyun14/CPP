#include <iostream>
#include <map>
using namespace std;

// map

	/* ���� �����ϴ� �����͸� Ű(Key)�� ��(Value) ���� ���·� ����ϴ� ���� �����̳��̴�.
	   ���ĵ� ��ġ�� �����͸� �����Ѵٴ� ������ �˻� �ӵ��� �����ٴ� Ư¡�� �ִ�.
	   �⺻������ Ű�� �ߺ��� ������� �ʴ´�.
	*/


/*
coding:3
dohyun : 1
hello : 2
0
Coke : 0
STL : 4
coding : 3
dohyun : 1
hello : 2
*/
int main()
{
	// string�� �������� �������� �����ȴ�.
	map<string, int> m;
	m["dohyun"] = 1;
	m["hello"] = 2;
	m["coding"] = 3;
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++)
		cout << iter->first << ":" << iter->second << endl;
	m["STL"] = 4;
	cout << m["Coke"] << endl;
	for (iter = m.begin(); iter != m.end(); iter++)
		cout << iter->first << ":" << iter->second << endl;
	return 0;
}