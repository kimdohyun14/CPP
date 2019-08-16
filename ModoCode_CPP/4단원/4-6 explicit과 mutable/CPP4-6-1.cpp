// explicit, mutable 에 대해서 알아보자.
// explicit는  C++에서 원하지 않는 암시적 변환을 할 수 업도록 컴파일러에게 명시
// explicit을 사용하면 이 생성자를 이용한 암시적 변환이 불가능하다.
#include <iostream>

class MyString {
	char* string_content; // 문자열 데이터를 가리키는 포인터
	int string_length;    // 문자열 길이

	int memory_capacity;  // 할당한 크기

public:
	// capacity 만큼 미리 할당한다. (explicit 키워드 사용)
	explicit MyString(int capacity); 

	// 문자열로부터 생성
	MyString(const char* str);

	// 복사 생성자
	MyString(const MyString& str);

	// 소멸자
	~MyString();

	int length() const;
};

MyString::MyString(int capacity) {
	string_content = new char[capacity];
	string_length = 0;
	memory_capacity = capacity;
}

MyString::MyString(const char* str) {
	string_length = 0;
	while(str[string_length++]) { }

	string_content = new char[string_length];
	memory_capacity = string_length;

	// 문자열 복사
	for (int i = 0; i != string_length; ++i)
		string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; ++i)
		string_content[i] = str.string_content[i];

	memory_capacity = string_length;
}

MyString::~MyString() {
	delete[] string_content;
}

int MyString::length() const {
	return string_length;
}

int main() {
	MyString s(3); // MyString(int capacity)를 통해 생성한다.
}

// explicit 키워드를 이용하면 암시적 변환을 막을 수 있다.
// MyString s(3);  허용
// MyString s = 3; 컴파일 오류