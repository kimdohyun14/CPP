//직접 만드는 문자열 클래스
//1. 문자로부터의 문자열 생성, C 문자열 (char*)로 부터의 생성
//2. 문자열 길이를 구하는 함수
//3. 문자열 뒤에 다른 문자열 붙이기
//4. 문자열 내에 포함되어 있는 문자열 구하기
//5. 문자열이 같은지 비교
//6. 문자열 크기 비교 (사전순)

//MyString 클래스에서 멤버 변수로 필요한 것들
//* 문자열 데이터가 저장된 공간을 가리키는 포인터
//* 문자열 데이터의 길이
#include <iostream>
#include <cstring>

class MyString {
	char* string_content;  //문자열 데이터를 가리키는 포인터
	int string_length;     //문자열 길이

public:
	//문자 하나로 생성
	MyString(char c);

	//문자열로 부터 생성
	MyString(const char* str);

	//복사 생성자
	MyString(const MyString& str);

	//assign 함수
	//지정하다 라는 뜻을 가지는 함수
	//'='과 동일한 역할을 한다.
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);

	//소멸자
	~MyString();

	int length() const;

	void print() const;
	void println() const;
};

// (널 종료 문자열)을 뺀 실제 '문자'만 저장한다.
// 이유 : 실제 문자열의 길이를 저장한 string_length가 있기 때문에

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
}

//내부 멤버 변수의 값을 바꾸지 않는다면 함수를 상수로 정의하자.
MyString::MyString(const char* str) {
	string_length = strlen(str);
	string_content = new char[string_length];

	for (int i = 0; i < string_length; ++i) {
		string_content[i] = str[i];
	}
}

//복사 생성자
MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];
	for (int i = 0; i < string_length; ++i) {
		string_content[i] = str.string_content[i];
	}
}

MyString::~MyString() {
	delete[] string_content;
}

int MyString::length() const{
	return string_length;
}

void MyString::print() const{
	for (int i = 0; i < string_length; ++i) {
		std::cout << string_content[i];
	}
}

void MyString::println() const {
	for (int i = 0; i < string_length; ++i) {
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}

//인자로 받은 문자열의 크기가 원래의 문자열의 크기보다 작다면 굳이 동적할당 x
MyString& MyString::assign(const MyString& str) {
	if (str.string_length > string_length) {
		//다시 할당을 해줘야만 한다.
		delete[] string_content;

		string_content = new char[str.string_length];
	}

	for (int i = 0; i != str.string_length; ++i) {
		string_content[i] = str.string_content[i];
	}

	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > string_length) {
		//다시 할당을 해줘야만 한다.
		delete[] string_content;

		string_content = new char[str_length];
	}

	for (int i = 0; i != str_length; ++i) {
		string_content[i] = str[i];
	}

	string_length = str_length;

	return *this;
}

int main() {
	MyString str1("hello world!");
	MyString str2(str1);

	str1.println();
	str2.println();

	return 0;
}



