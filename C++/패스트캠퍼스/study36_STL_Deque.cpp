#include <iostream>
#include <deque>
using namespace std;

// C++ STL 시퀀스 컨테이너

	/* 1. STL 시퀀스 컨테이너 라이브러리는 매우 활용도가 높은 자료구조를 제공한다.
	   2. 기존의 C언어를 이용하면 구현하기 까다로웠던 다양한 자료구조를 손쉽게 이용할 수 있다.
	   3. 가장 많이 사용되는 시퀀스 컨테이너는 벡터(Vector)와 덱(Deque)이다. 

	  - vector
	  - deque
	  - list
	  - forward list(순방향 리스트)
	*/

// 덱

	/* 덱은 양 끝에서 데이터를 넣거나 뺄 수 있는 자료구조이다.
	   
	   - push_front() : 덱의 앞에 데이터 삽입
	   - pop_front()  : 덱의 앞에서 데이터 꺼냄
	   - push_back()  : 덱의 뒤에 데이터 삽입
	   - pop_back()   : 덱의 뒤에서 데이터 꺼냄
	   - insert()     : 덱의 특정 위치에 데이터를 삽입
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
	
	dq.clear(); // 덱을 비운다.
	cout << dq.empty() << endl;
	return 0;
}