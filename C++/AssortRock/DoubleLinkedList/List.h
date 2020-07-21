// #pragma once : 이 헤더파일을 딱 1번만 포함시키겠다 라는 의미이다.
#pragma once

#include <iostream>
using namespace std;

// 헤더파일에는 보통 함수 선언부분을 만들어준다.
#define NAME_SIZE 32

enum OUTPUT_TYPE
{
	OT_NONE,
	OT_OUTPUT,
	OT_INVERSE
};

enum SORT_TYPE
{
	ST_NONE,
	ST_NUMBER,
	ST_AVG
};

enum SORT_OPTION
{
	SO_NONE,
	SO_CRIVE,
	SO_DESCRIVE
};

typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
}STUDENT, * PSTUDENT;

typedef struct _tagNode
{
	STUDENT tStudent;
	_tagNode* pNext;
	_tagNode* pPrev;
}NODE, * PNODE;

typedef struct _tagList
{
	// pBegin과 pEnd는 명시적으로 처음과 끝을 의미하도록 만든다.
	// 실제 데이터를 저장하는 노드는 아니다.
	// 실제 데이터를 저장하는 노드는 pBegin과 pEnd 사이에 존재하게 만들어준다.
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, * PLIST;

// 헤더파일에서 선언부분과 정의부분을 동시에 구현한다고 하면
// main.obj 와 List.obj가 만들어진다.
// 실제 obj파일에서 헤더의 기능을 끌어다가 쓸 때(두 개 이상의 cpp파일에서 끌어다가 쓸 경우)
// main.obj과 List.obj 둘다 List.h 헤더의 기능을 쓰기 때문에 => 이를 중복으로 인식한다.
// 앞에 static을 붙이면 각각 따로 처리할 수 있게 되면서, LINK 오류를 피할 수 있다.
static int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}

static void InputString(char* pString, int iSize)
{
	cin.clear();
	// 입력버퍼에 \n이 남아있을 수 있으므로
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}

void InitList(PLIST pList);
void ClearList(PLIST pList);
void DestroyList(PLIST pList);
void Push_Back(PLIST pList);
void Push_Front(PLIST pList);
void OutputStudent(const PSTUDENT pStudent);
void Output(PLIST pList);
void Search(PLIST pList);
void Delete(PLIST pList);
void Sort(PLIST pList);