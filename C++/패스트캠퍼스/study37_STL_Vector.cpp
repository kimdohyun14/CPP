#include <iostream>
#include <vector>
using namespace std;

// ����

	/* ���ʹ� ���ʿ����� �����͸� �ְų� �� �� �ִ� �ڷᱸ���̴�.
	   �迭ó�� ����ϱ⿡ �����ϴٴ� ������ �˰��� ����Ǯ�̿��� ���� ���� ���ȴ�.
	   
	   ������ ����Ǯ�̿����� �յڷ� ���Ұ� �߰��Ǵ� ��찡 ������ ���� ���ҿ� �����ؾ� �ϴ� ��찡 ����
	   �� �ڷᱸ���� ������ �� �Ϲ����� ��� ���������� �� ȿ�����̴�.
	   
	   - push_back() : ���� �ڿ� ������ ����
	   - pop_back()  : ���� �ڿ��� �����͸� ����
	   - insert()    : ������ Ư�� ��ġ�� �����͸� ����
	*/

// 3 7 7 7 5 8
// 1
// 1 1 1 1 1 1 1 1 1 1
// 1 1 1 1 1 5 1 1 1 1
// 10
int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(8);
	vector<int>::iterator iter = v.begin();
	v.insert(iter + 1, 3, 7);
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	cout << endl;
	v.clear();
	cout << v.empty() << endl;
	v.assign(10, 1);
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	cout << endl;
	v[5] = 5;
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
	cout << endl;
	cout << v.size() << endl;
	return 0;
}