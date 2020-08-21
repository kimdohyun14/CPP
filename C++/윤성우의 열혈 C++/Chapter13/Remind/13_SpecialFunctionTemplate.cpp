#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

// 함수 Max를 char* 형에 대해서 특수화
template<>
char* Max(char* a, char* b)
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}


// 함수 Max를 const char* 형에 대해서 특수화
template<>
const char* Max(const char* a, const char* b)
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main()
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;
	return 0;
}