// 산술 연산자 오버로딩
// 비교 연산자 오버로딩
// 대입 연산자 오버로딩
// 에 대해서 알아본다.

// :: (범위지정) . (멤버 지정) * (멤버 포인터로 멤버 지정)을 제외한
// +, -, *, +=, -=, >=, ==, &&, ->, ++, --, [], ()까지 사용할 수 있다.
// 이러한 기본 연산자들을 직접 사용자가 정의하는 것을
// 연산자 오버로딩(overloading)이라고 한다.

// -> 기본 연산자를 내가 설계한 클래스에 맞게 직접 사용하는 것을
// 연산자 오버로딩이라고 한다.

// MyStirng의 ==연산자 오버로딩
// (리턴타입) operator(연산자) (연산자가 받는 인자)
// 함수 이름으로 연산자를 절대 넣을 수 없다.
// 연산자는 그 결과값이 언제나 bool이고,
// 인자로는 == 로 비교하는 것 하나만 받게 된다.

#include <cstring>
#include <iostream>
#include <algorithm>

class MyString {
	char* string_content;
	int string_length;

	int memory_capacity;

public:
	MyString(char c);
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();

	int length() const;
	int capacity() const;
	void reserve(int size);

	void print() const;
	void println() const;

	char at(int i) const;

	int compare(MyString& str);
	bool operator==(MyString& str);
};

MyString::MyString(char c) {
	string_content = new char[1];
	string_content[0] = c;
	string_length = 1;
	memory_capacity = 1;
}

MyString::MyString(const char* str) {
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

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

int MyString::length() const { return string_length; }
void MyString::print() const {
	for (int i = 0; i != string_length; ++i)
		std::cout << string_content[i];
}

void MyString::println () const {
	for (int i = 0; i != string_length; ++i)
		std::cout << string_content[i];

	std::cout << std::endl;
}

int MyString::capacity() const { return memory_capacity; }
void MyString::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; ++i)
			string_content[i] = prev_string_content[i];

		delete[] prev_string_content;
	}
}

char MyString::at(int i) const {
	if (i >= string_length || i < 0)
		return 0;
	else
		string_content[i];
}

int MyString::compare(MyString& str) {
	int size = string_length > str.string_length ? str.string_length : string_length;

	for (int i = 0; i < size; ++i) {
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}

	if (string_length == str.string_length) return 0;

	else if (string_length > str.string_length)
		return 1;
	else - 1;
}

bool MyString::operator==(MyString& str) {
	return !compare(str); // str과 같으면 compare에서 0을 리턴
}

int main() {
	MyString str1("a word");
	MyString str2("sentence");
	MyString str3("sentence");

	if (str1 == str2)
		std::cout << "str1 와 str2 같다." << std::endl;
	else
		std::cout << "str1 와 str2 는 다르다." << std::endl;

	if (str2 == str3)
		std::cout << "str2 와 str3 는 같다." << std::endl;
	else
		std::cout << "str2 와 str3 는 다르다." << std::endl;

	return 0;
}