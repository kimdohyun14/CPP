#include <iostream>

// C++�� ���ӽ����̽�
/* ���ӽ����̽�(namespace)�� Ư���� ������ �̸��� ������ �� �ֵ��� �ϴ� ����
   ���� �ٸ� �����ڰ� �������� ������Ʈ�� ������ ��, ���� ������ ����� �ϳ��� ��ĥ �� �ֵ��� ���ش�. */

// using Ű���带 �̿��ؼ� ǥ�� ���̺귯��(std)�� ��� ����ϵ��� ó���� �� �ִ�.
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
    A::function(); // ���� ���� ������ ::
    B::function();
    return 0;
}