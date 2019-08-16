// 문자열 삽입하기 (insert)
#include <iostream>
#include <cstring>

class MyString {
	char* string_content;  //문자열 데이터를 가리키는 포인터
	int string_length;     //문자열 길이
	int memory_capacity;   //현재 할당된 메모리 공간의 크기를 나타냄.
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

	//현재 할당된 메모리 공간의 크기를 반환
	int capacity() const;
	//할당할 문자열의 크기를 미리 예약해놓는 함수
	void reserve(int size);
	//특정 위치의 문자를 얻는 함수
	char at(int i) const;

	// 입력 위치를 받는 경우, 그 입력 위치 '앞'에 문자를 insert한다.
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
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

int MyString::length() const {
	return string_length;
}

void MyString::print() const {
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
	if (str.string_length > memory_capacity) {
		//다시 할당을 해줘야만 한다.
		delete[] string_content;

		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}

	for (int i = 0; i != str.string_length; ++i) {
		string_content[i] = str.string_content[i];
	}

	string_length = str.string_length;

	return *this;
}

MyString& MyString::assign(const char* str) {
	int str_length = strlen(str);
	if (str_length > memory_capacity) {
		//다시 할당을 해줘야만 한다.
		delete[] string_content;

		string_content = new char[str_length];
		memory_capacity = str_length;
	}

	for (int i = 0; i != str_length; ++i) {
		string_content[i] = str[i];
	}

	string_length = str_length;

	return *this;
}

int MyString::capacity() const {
	return memory_capacity;
}

void MyString::reserve(int size) {
	//할당되는 크기가 기존보다 크다면 다시 할당
	if (size > memory_capacity) {
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; ++i) {
			string_content[i] = prev_string_content[i];
		}

		delete[] prev_string_content;
	}

	// 만일 예약하려는 size가 현재 capacity보다 작다면
	// 아무것도 안해도 된다.
}

char MyString::at(int i) const {
	if (i >= string_length || i < 0)
		return NULL;
	else
		return string_content[i];
}

MyString& MyString::insert(int loc, const char* str) {
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c) {
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, const MyString& str) {
	// i의 위치 바로 앞에 문자를 삽입하게 된다.
	// abc 라는 문자열에 insert(1, 'd') -> adbc

	// 범위를 벗어나는 입력에 대해서는 수행하지 않는다.
	if (loc<0 || loc > string_length) return *this;

	if (string_length + str.string_length > memory_capacity) {
		// 새롭게 동적으로 할당해야 한다.

		/* 동적할당 최적화 */
		// memory_capacity = string_length + str.string_length;
		// 새로 할당해야 할 메모리 크기 (string_length + str.string_length)가 
		// memory_capacity의 두 배 이하라면, memory_capacity를 두 배로 할당한다.
		if (memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;

		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];

		//일단 insert 되는 부분 직전까지의 내용을 복사한다.
		int i;
		for (i = 0; i < loc; ++i) {
			string_content[i] = prev_string_content[i];
		}

		//그리고 새롭게 insert되는 문자열을 넣는다.
		for (int j = 0; j != str.string_length; ++j) {
			string_content[i + j] = str.string_content[j];
		}

		//이제 다시 남은 원본 문자열의 나머지 뒷부분을 복사한다.
		for (; i < string_length; ++i) {
			string_content[str.string_length + i] = prev_string_content[i];
		}

		delete[] prev_string_content;

		string_length = string_length + str.string_length;
		return *this;
	}

	// 만일 초과하지 않는 경우 굳이 동적할당을 할 필요가 없다.
	// 효율적으로 insert하기 위해, 밀리는 부분을 먼저 뒤로 밀어버린다.

	for (int i = string_length - 1; i >= loc; --i) {
		// 뒤로 밀기. 이 때 원래의 문자열 데이터가 사라지지 않게한다.
		string_content[i + str.string_length] = string_content[i];
	}

	// 그리고 insert 되는 문자 다시 집어넣기
	for (int i = 0; i < str.string_length; ++i) {
		string_content[i + loc] = str.string_content[i];
	}

	string_length = string_length + str.string_length;
	return *this;
}

int main() {
	MyString str1("very very very long string");
	MyString str2("<some string inserted between>");
	str1.reserve(30);

	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();

	str1.insert(5, str2);
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();
	return 0;
}


