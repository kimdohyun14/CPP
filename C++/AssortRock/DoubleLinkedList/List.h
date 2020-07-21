// #pragma once : �� ��������� �� 1���� ���Խ�Ű�ڴ� ��� �ǹ��̴�.
#pragma once

#include <iostream>
using namespace std;

// ������Ͽ��� ���� �Լ� ����κ��� ������ش�.
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
	// pBegin�� pEnd�� ��������� ó���� ���� �ǹ��ϵ��� �����.
	// ���� �����͸� �����ϴ� ���� �ƴϴ�.
	// ���� �����͸� �����ϴ� ���� pBegin�� pEnd ���̿� �����ϰ� ������ش�.
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, * PLIST;

// ������Ͽ��� ����κа� ���Ǻκ��� ���ÿ� �����Ѵٰ� �ϸ�
// main.obj �� List.obj�� ���������.
// ���� obj���Ͽ��� ����� ����� ����ٰ� �� ��(�� �� �̻��� cpp���Ͽ��� ����ٰ� �� ���)
// main.obj�� List.obj �Ѵ� List.h ����� ����� ���� ������ => �̸� �ߺ����� �ν��Ѵ�.
// �տ� static�� ���̸� ���� ���� ó���� �� �ְ� �Ǹ鼭, LINK ������ ���� �� �ִ�.
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
	// �Է¹��ۿ� \n�� �������� �� �����Ƿ�
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