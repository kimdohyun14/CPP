#include <iostream>
#include <vector>
using namespace std;

// 벡터

	/* 벡터는 뒤쪽에서만 데이터를 넣거나 뺄 수 있는 자료구조이다.
	   배열처럼 사용하기에 적합하다는 점에서 알고리즘 문제풀이에서 가장 많이 사용된다.
	   
	   실제로 문제풀이에서는 앞뒤로 원소가 추가되는 경우가 적으며 임의 원소에 접근해야 하는 경우가 많아
	   덱 자료구조와 비교했을 때 일반적인 경우 성능적으로 더 효율적이다.
	   
	   - push_back() : 벡터 뒤에 데이터 삽입
	   - pop_back()  : 벡터 뒤에서 데이터를 꺼냄
	   - insert()    : 벡터의 특정 위치에 데이터를 삽입
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