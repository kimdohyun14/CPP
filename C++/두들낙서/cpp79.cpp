#include <iostream>
#include <string>
using namespace std;

class Image {
public:
	operator string() {
		return "사진";
	}
};

class Message {
public:
	Message(int sendTime, string sendName)
		:sendTime(sendTime), sendName(sendName) {}

	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }
	virtual string GetContent() const { return ""; }
private:
	int sendTime;
	string sendName;
};

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName), text(text) {}

	string GetText() const { return text; }
	string GetContent() const {
		return text;
	}
private:
	string text;
};

class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image* image)
		: Message(sendTime, sendName), p_image(image) {}

	Image* GetImage() const { return p_image; }
	string GetContent() const {
		return (string)*p_image;
	}
private:
	Image* p_image;
};

//상속이 필요한 이유
//레퍼런스로 넘겨줘도 동적 바인딩이 일어남
//포인터로 넘겨줘도 동적 바인딩이 일어남
//이렇게 깔끔하게 타입 하나로 함수를 만들 수 있는 장점
void printMessage(const Message& m) {
	cout << "보낸 시간 : " << m.GetSendTime() << endl;
	cout << "보낸 사람 : " << m.GetSendName() << endl;
	cout << "  내 용   : " << m.GetContent() << endl;
	cout << endl;
}

int main() {
	Image* p_dogImage = new Image();

	//포인터를 사용하는 이유,
	//그냥 Message로 담게 되면 sendTime, sendName은 담을 수 있지만
	//그 외의 오버라이딩 된 변수들이나 함수들을 담을 수 없기 때문이다.
	Message* messages[] = {
		new TextMessage(10, "두들", "안녕"),
		new TextMessage(11, "두들", "안녕"),
		new TextMessage(12, "두들", "안녕"),
		new ImageMessage(20, "두들", p_dogImage)
	};

	for (Message* m : messages) {
		printMessage(*m);
	}

	delete p_dogImage;
	for (Message* m : messages) {
		delete m;
	}
	return 0;
}