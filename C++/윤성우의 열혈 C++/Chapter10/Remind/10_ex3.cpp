#include <iostream>
using namespace std;

class Point
{
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) { }
	void ShowPosition()const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}

	Point& operator++()
	{
		++xpos;
		++ypos;
		return *this;
	}

	// 후위 증가
	const Point operator++(int)
	{
		const Point retobj(xpos, ypos);
		++xpos;
		++ypos;
		return retobj;
	}

	friend Point& operator--(Point& ref);
	friend const Point operator--(Point& ref, int);
};

Point& operator--(Point& ref)
{
	--ref.xpos;
	--ref.ypos;
	return ref;
}

const Point operator--(Point& ref, int)
{
	const Point retobj(ref);
	--ref.xpos;
	--ref.ypos;
	return retobj;
}

int main()
{
	Point pos(3, 5);
	Point cpy;
	cpy = pos--;
	cpy.ShowPosition();
	pos.ShowPosition();

	cpy = pos++;
	cpy.ShowPosition();
	pos.ShowPosition();
	return 0;
}