#include <iostream>
using namespace std;

class Rectangle {
private:
	int width;
	int height;
public:
	Rectangle(int wid, int hei) :width(wid), height(hei){ }
	void ShowAreaInfo() const{
		cout << "¸éÀû: " << width * height << endl;
	}
};

class Square : public Rectangle {
public:
	Square(int side) : Rectangle(side,side){ }
};

int main() {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}