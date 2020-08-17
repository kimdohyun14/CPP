#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	// 덧셈연산이라는 것이 원래 연산의 대상이 되는 피연산자의 값을 변경하는 것이
	// 아닌, 새로운 연산의 결과를 만들어내는 것이기 때문에 const 붙이자.
	Point operator+(const Point& ref) const
	{
		Point pos(xpos + ref.xpos, ypos + ref.ypos);
		return pos;
	}
};

int main()
{
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1.operator+(pos2);
	Point pos4 = pos1 + pos2;
	Point pos5 = pos4 + pos1;
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	pos4.ShowPosition();
	pos5.ShowPosition();
	return 0;
}