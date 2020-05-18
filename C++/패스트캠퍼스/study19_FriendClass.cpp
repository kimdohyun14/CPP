#include <iostream>
#include <ctime>
using namespace std;

// Friend Class

/* 멤버 함수 이외에도 Friend Class 형태로 사용할 수 있다.
   두 클래스가 서로 밀접한 연관성이 있으며 상대방의 private 멤버에 접근해야 한다면 클래스 자체를 friend로 선언할 수 있다. 
   
   Friend Class에서는 모든 멤버 함수가 특정 클래스의 friend이다.*/

// friend class는 많이 사용하게 되면 정보 은닉의 효과가 많이 떨어질 수 있다.

class Time
{
    friend class Date; // Date 클래스에서 Time 클래스를 이용할 수 있다.
private:
    int hour, min, sec;
public:
    void setCurrentTime()
    {
        time_t currentTime = time(NULL);
        struct tm* p = localtime(&currentTime);
        hour = p->tm_hour;
        min = p->tm_min;
        sec = p->tm_sec;
    }
};

class Date
{
private:
    int year, month, day;
public:
    Date(int year, int month, int day) : year(year), month(month), day(day) {}
    void show(const Time& t)
    {
        cout << "지정한 날짜: " << year << "년 " << month << "월 " << day << "일" << '\n';
        cout << "현재 시간: " << t.hour << ":" << t.min << ":" << t.sec << '\n';
    }
};

int main()
{
    Time time;
    time.setCurrentTime();
    Date date = Date(2020, 5, 18);
    date.show(time);
    return 0;
}