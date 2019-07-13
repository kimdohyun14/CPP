#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* ti, const char* ib, int pri)
		:price(pri) {
		title = new char[strlen(ti) + 1];
		isbn = new char[strlen(ib) + 1];
		strcpy(title, ti);
		strcpy(isbn, ib);
	}
	void ShowBookInfo()  {
		cout << "����: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "����: " << price << endl;
	}
	~Book() {
		delete[]title;
		delete[]isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* ti, const char* ib, int pri, const char* drm)
		:Book(ti, ib, pri) {
		DRMKey = new char[strlen(drm) + 1];
		strcpy(DRMKey, drm);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "����Ű: " << DRMKey << endl;
	}
	~EBook() {
		delete[] DRMKey;
	}
};

int main() {
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}