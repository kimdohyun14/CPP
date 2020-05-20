#include <iostream>
#include <set>
using namespace std;

// C++ STL 연관 컨테이너

	/* 1. STL 연관 컨테이너 라이브러리는 매우 활용도가 높은 자료구조를 제공한다.
	   2. 연관 컨테이너는 키(Key)와 값(Value)형태의 관련 있는 데이터를 쌍으로 저장하는 컨테이너.
	   3. 가장 많이 사용되는 시퀀스 컨테이너는 집합(Set)과 맵(Map)
	   
	   - set(집합)
	   - multiset(멀티 집합)
	   - map(맵)
	   - multimap(멀티 맵)
	*/

// set

	/* 집합은 저장하는 데이터를 키(Key)로 사용하는 연관 컨테이너이다.
	   정렬된 위치에 데이터를 삽입한다는 점에서 검색 속도가 빠르다는 특징이 있다.
	   기본적으로 키의 중복을 허용하지 않는다.
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