#ifndef __ACCOUNT_ARRAY_H__
#define __ACCOUNT_ARRAY_H__

#include "Account.h"
typedef Account* ACCOUNT_PTR;

class BoundCheckAccountPtrArray
{
private:
	ACCOUNT_PTR* arr;
	int arrlen;
	BoundCheckAccountPtrArray(const  BoundCheckAccountPtrArray& arr) { } // 복사 생성자
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) { } // 대입 연산자를 차단.

public:
	BoundCheckAccountPtrArray(int len = 100);
	ACCOUNT_PTR& operator[](int idx);
	ACCOUNT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckAccountPtrArray();
};
#endif