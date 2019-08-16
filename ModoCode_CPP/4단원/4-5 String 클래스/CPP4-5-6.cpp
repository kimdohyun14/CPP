// 크기 비교 함수 compare
// '크기'를 비교한다는 의미는 사전식으로 배열해서 어떤 문자열이 더 뒤에 오는지 판단
// 문자열 전체를 정렬하는 함수라던지, 기존 C 언어에서 strcmp 함수
#include <iostream>
#include <cstring>
#include <algorithm>

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

	// loc은 해당위치의 문자 앞을 의미, num은 지우는 문자의 수를 의미
	MyString& erase(int loc, int num);

	//find_from에서부터 시작해서 가장 첫 번째 str의 위치를 리턴하게 된다.
	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;

	int compare(const MyString& str) const;
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

MyString& MyString::erase(int loc, int num) {

	// loc의 앞부터 시작해서 num개의 문자를 지운다.
	if (num < 0 || loc < 0 || loc > string_length)
		return *this;

	// 지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 온다고 생각하자.
	for (int i = loc + num; i < string_length; ++i) {
		string_content[i - num] = string_content[i];
	}
	// -> string_length를 도입해서 뒤에 어떠한 정보가 오든지 간에 신경을 안써도 된다.
	// 앞으로 문자들을 끌고 오면서 뒤의 문자들을 초기화 하지 않았지만
	// string_length 값을 처리했기 때문에 뒤의 문자들에 신경 쓰지 않아도 된다.
	string_length -= num;
	return *this;
}

int MyString::find(int find_from, MyString& str) const {
	int i, j;
	if (str.string_length == 0) return -1;
	for (i = find_from; i < string_length - str.string_length; ++i) {
		// find_from부터 시작해서 string_content와 str가 완벽히 일치한다면
		// 그 위치를 리턴하고, 찾지 못할 경우 -1을 리턴한다.
		for (j = 0; j < str.string_length; ++j) {
			if (string_content[i + j] != str.string_content[j])
				break; // 하나라도 다른 부분이 있다면 실패.
		}

		if (j == str.string_length)
			return i;
	}
	return -1; // 찾지 못했음.
}

int MyString::find(int find_from, const char* str) const {
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const {
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const {
	// (*this) - (str) 을 수행해서 그 1, 0, -1 로 그 결과를 리턴한다.
	// 1은 (*this)가 사전식으로 더 뒤에 온다는 의미
	// 0은 두 문자열이 같다는 의미
	// -1은 (*this)이 사전식으로 더 앞에 온다는 의미

	for (int i = 0; i < std::min(string_length, str.string_length); ++i) {
		if (string_content[i] > str.string_content[i])
			return 1;
		else if (string_content[i] < str.string_content[i])
			return -1;
	}

	// 여기 까지 했는데 끝나지 않았다면 앞 부분 까지 모두 똑같은 것이므로
	// 만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열이 된다.
	if (string_length == str.string_length) return 0;

	// abd 와 abcd 의 크기 비교는 abcd 가 더 뒤에 오게 된다.
	else if (string_length > str.string_length)
		return 1;
	else
		return -1;
}

int main() {
	MyString str1("abcdef");
	MyString str2("abcde");

	// 결과값이 1이 나온다는 의미는
	// str1이 str2보다 사전순으로 뒤에 있다는 뜻이다.
	std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;
	return 0;
}

/* 지금 까지 배운 인터페이스 */

// 1. 문자 혹은 문자열을 생성할 수 있는 생성자와 복사 생성자
// 2. 문자열의 길이를 리턴하는 함수 (length)
// 3. 문자열 대입 함수 (assign)
// 4. 문자열 메모리 할당 함수 (reserve) 및 현재 할당된 크기를 알아오는 함수(capacity)
// 5. 특정 위치의 문자를 리턴하는 함수 (at)
// 6. 특정 위치에 특정 문자열을 삽입하는 함수(insert)
// 7. 특정 위치의 특정 개수의 문자를 지우는 함수(erase)
// 8. 특정 위치를 시작으로 특정 문자열을 검색하는 함수(find)
// 9. 두 문자열을 사전식 비교하는 함수(compare)


