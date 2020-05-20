#include <iostream>
#include <map>
using namespace std;

// map

	/* 맵은 저장하는 데이터를 키(Key)와 값(Value) 쌍의 형태로 사용하는 연관 컨테이너이다.
	   정렬된 위치에 데이터를 삽입한다는 점에서 검색 속도가 빠르다는 특징이 있다.
	   기본적으로 키의 중복을 허용하지 않는다.
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
	// string을 사전순을 기준으로 나열된다.
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