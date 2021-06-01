//생성/소멸자 실행 순서와 가상 소멸자
#include <iostream>
using namespace std;

class Ice {
public:
	Ice() { cout << "Ice()" << endl; }
	~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
public:
	Pat() { cout << "Pat()" << endl; }
	~Pat() { cout << "~Pat()" << endl; }
};

class Bingsoo {
public:
	Bingsoo() { 
		cout << "Bingsoo()" << endl;
		ice = new Ice;
	}
	//가상 소멸자
	virtual ~Bingsoo() { 
		cout << "~Bingsoo()" << endl;
		delete ice;
	}

private:
	Ice* ice;
};

class PatBingsoo : public Bingsoo {
public:
	PatBingsoo() { 
		cout << "PatBingsoo()" << endl;
		pat = new Pat;
	}
	~PatBingsoo() { 
		cout << "~PatBingsoo()" << endl;
		delete pat;
	}

private:
	Pat* pat;
};

int main() {
	//기본적으로 타입이 Bingsoo이기 때문에 CPP은 정적 바인딩이 된다.
	//그렇지만 가상 소멸자를 선언해주면 CPP은 소멸할 때 동적 바인딩으로 모든 소멸자를 확인하여 소멸시켜준다.--+9
	Bingsoo* p = new PatBingsoo;
	delete p;
}