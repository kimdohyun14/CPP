#ifndef __BOUND_CHECK_ARRAY_H
#define __BOUND_CHECK_ARRAY_H

#include <iostream>
using namespace std;

template<typename T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const  BoundCheckArray& arr) { } // 복사 생성자
	BoundCheckArray& operator=(const BoundCheckArray& arr) { } // 대입 연산자를 차단.

public:
	BoundCheckArray(int len = 100);
	T& operator[](int idx);
	T operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};
#endif

template<typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
	arr = new T[len];
}

template<typename T>
T& BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
T BoundCheckArray<T>::operator[](int idx) const // const키워드가 붙은 것도 오버로딩의 하나이다.
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template<typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[] arr;
}