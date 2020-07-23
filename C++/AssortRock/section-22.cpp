#include <iostream>

using namespace std;

// pp는 int* 타입의 p변수의 주소를 가지게 된다.
void Test(int** pp)
{
	*pp = new int;
}

int main()
{
	//int* p = NULL;
	//Test(&p);

	FILE* pFile = NULL;

	// 1번 인자 : 파일의 이중포인터, fopen_s는 call-by-address 형태
	// 2번 인자 : 파일 경로이다. 파일이 생성되는 기준 경로는 현재 프로젝트가 있는 폴더 기준이다.
	// 만약 실행파일로 실행했을 경우에는 해당 exe 파일이 있는 경로를 기준으로 생성해준다.
	// 3번 인자 : 파일 모드이다. 모드는 크게 2가지로 구분
	// 파일 읽기, 쓰기, 접근이 있고 파일 형태, 텍스트 파일, 바이너리 파일
	// 2가지 모드가 있어서 합쳐서 사용한다.
	// r : 읽기 w : 쓰기 a : 접근 t : 텍스트파일 b : 바이너리 파일

	/*
	fopen_s(&pFile, "summer.txt", "wt");

	if (pFile != NULL)
	{
		// fwrite, fread 2개의 함수가 제공
		// fputs, fgets 도 제공
		const char* pText = "abcd";
		// 1번 인자 : 저장하고자 하는 값의 메모리 주소를 넣어준다.
		// 2번 인자 : 저장하고자 하는 값의 변수타입의 메모리 크기를 넣어준다.
		// 3번 인자 : 저장하고자 하는 값의 개수를 넣어준다.
		// 4번 인자 : 저장할 파일의 스트림을 넣어준다.
		fwrite(pText, 1, 4, pFile);

		// 파일을 열었으면 닫아준다.
		fclose(pFile);

		cout << "파일 만들기 성공" << endl;
	}
	*/

	fopen_s(&pFile, "summer.txt", "rt");

	if (pFile)
	{
		char strText[5] = {};

		fread(strText, 1, 4, pFile);

		cout << strText << endl;

		fclose(pFile);

		cout << "파일 만들기 성공" << endl;
	}

	return 0;
}