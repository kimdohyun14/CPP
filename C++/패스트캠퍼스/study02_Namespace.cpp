#include <iostream>

// C++의 네임스페이스
/* 네임스페이스(namespace)는 특정한 영역에 이름을 설정할 수 있도록 하는 문법
   서로 다른 개발자가 공동으로 프로젝트를 진행할 때, 각자 개발한 모듈을 하나로 합칠 수 있도록 해준다. */

// using 키워드를 이용해서 표준 라이브러리(std)를 모두 사용하도록 처리할 수 있다.
// using namespace std;

namespace A
{
    void function()
    {
        std::cout << "A namespace" << std::endl;
    }
}

namespace B
{
    void function()
    {
        std::cout << "B namespace" << std::endl;
    }
}

int main()
{
    A::function(); // 범위 지정 연산자 ::
    B::function();
    return 0;
}