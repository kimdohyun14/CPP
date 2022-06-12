using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Concurrent; // ConcurrentBag
using System.Threading.Tasks;        // Task 사용
using System.Threading;              // Thread 사용

namespace Program
{
    /* 동적 배열 (Dynamic Array)
     * 
     * - 배열요소가 몇 개가 필요한 지 미리 알 수 없는 경우가 있으며, 중간에 필요에 따라 배열을 확장해야 하는 경우도 있다!
     * - .NET 에서는 이러한 동적 배열을 지원하는 클래스로 ArrayList 와 List<T> 가 있다.
     * 
     * ArrayList 는 Object 타입이라 모든 타입을 다 받을 수 있지만, 박싱/언박싱을 피할 수 없다.
     * List<T> 는 Generic 타입으로 사용하고자 하는 타입만 받을 수 있지만, 박싱/언박싱을 피할 수 있다.
     * 
     * 이들은 동적 배열 클래스들은 배열 확장이 필요한 경우, 내부적으로 배열 크기가 2배인 새로운 배열을 생성하고,
     * 모든 기존 배열 요소들을 새로운 배열에 복사한 후 기존 배열을 해제한다.
     * => 그래서 보통 Capacity를 미리 넉넉하게 잡고 사용하는 경우 배열 확장을 피할 수 있게 된다.
     * 
     * 조회할 때)
     * - Index 로 조회한다면 O(1)
     * - Value 로 조회한다면 O(N), 다만 정렬된 배열이라면 이진 탐색으로 O(logN)
     * 
     * ArrayList 클래스
     * - 모든 배열 요소가 object 타입인 Non-generic 동적 배열 클래스
     * - .NET의 Non-generic 클래스들은 System.Collections 이름 영역 안에 있으며, 단점으로는 박싱/언박싱이 일어나게 된다.
     * - 배열의 요소를 읽어 사용할 때 object를 리턴하므로 일반적으로 원하는 타입으로 먼저 캐스팅한 후 사용하게 된다.
     * 
     * List<T> 클래스
     * - T 타입 Generics
     * - .NET Generic 클래스들은 System.Collections.Generic 이름 영역 안에 있다.
     * - List 클래스는 내부적으로 배열을 가지고 있으며, 동일한(Homogeneous) 타입의 데이터를 저장한다.
     * - 만약 Capacity(미리 할당된 배열 크기)가 부족하면 내부적으로 배열을 2배로 늘려 동적으로 배열을 확장 시키며 이때는 O(N) 이 걸린다.
     * - ArrayList 와 다르게 캐스팅을 할 필요가 없고, 박싱과 언박싱으로부터 문제를 발생시키지 않는다.
     * 
     * SortedList<TKey, TValue> 클래스
     * - Key 값으로 Value를 찾는 Map ADT 타입을 내부적으로 배열을 이용해 구현한 클래스다.
     * - .NET에서 Map ADT를 구현한 클래스로는 해시테이블을 이용한 HashTable/Dictionary 클래스
     * - 이진 검색 트리를 이용한 SortedDictionary
     * - 배열을 이용한 SortedList
     * 
     * SortedList 클래스는 내부적으로 키값으로 정렬된 배열을 가지고 있으며,
     * 이진 검색이 가능하기 때문에 O(logN)의 검색 시간이 소요된다.
     * 
     * 마찬가지로 미리 할당된 배열의 크기가 부족하게 되면 내부적으로 배열을 2배로 늘려 동적으로 배열을 확장한다.
     * 
     * ConcurrentBag 클래스
     * - .NET 4.0부터 멀티쓰레딩 환경에서 리스트를 보다 간편하게 사용할 수 있는 새로운 클래스인 ConcurrentBag<T> 가 제공된다.
     * - 리스트와 비슷하게 객체들의 컬렉션을 저장하는데, List<T> 와는 달리 입력 순서를 보장하지 않는다!
     * 
     * - 데이터 추가는 Add(), 읽는 것은 foreach문 혹은 TryPeek(), TryTake() 메서드를 사용한다.
     * - TryPeek()은 데이터를 읽기만 하는 것
     * - TryTake()는 데이터를 읽은 후 해당 요소를 ConcurrentBag에서 삭제하게 된다.
     * 
     * ConcurrentBag는 멀티쓰레드가 동시에 액세스할 수 있는데,
     * 스레드A 와 스레드B 가 ConcurrentBag에 데이터를 쓸 때,
     * 스레드A 가 1,2,3 을 넣고 // 스레드B 가 4,5,6 을 넣으면
     * 스레드A 가 ConcurrentBag을 다시 읽을 때, 자신이 쓴 1,2,3을 우선순위로 먼저 읽은 다음, 나머지 다른 스레드에 의해 입력된 요소들 4,5,6 을 읽게 된다.
     */
    class DArray
    {
        static void Main()
        {
            ArrayList myList = new ArrayList();
            myList.Add(90);
            myList.Add(50);
            myList.Add(15);

            int val = (int)myList[0];

            List<int> myList2 = new List<int>(); // capacity 0
            for(int i = 0; i < 10; i++)
            {
                myList2.Add(i);
                Console.WriteLine($"index {i} => myList2 Capacity : {myList2.Capacity}");
            }

            SortedList<int, string> sortList = new SortedList<int, string>();
            sortList.Add(1, "one");
            sortList.Add(2, "two");
            sortList.Add(3, "three");

            foreach(KeyValuePair<int, string> kvp in sortList)
            {
                Console.WriteLine($"{kvp.Key}:{kvp.Value}");
            }

            Console.WriteLine();

            // 첫번째 쓰레드는 100개의 숫자를 ConcurrentBag에 넣는 작업
            // 동시에 두번째 쓰레드는 10회 반복하는데, 1초마다 해당 ConcurrentBag의 내용을 출력한다.
            var bag = new ConcurrentBag<int>();

            // 데이터를 Bag에 넣는 쓰레드
            Task t1 = Task.Factory.StartNew(() =>
            {
                for(int i = 0; i < 100; i++)
                {
                    bag.Add(i);
                    Thread.Sleep(100);
                }
            });

            Task t2 = Task.Factory.StartNew(() =>
            {
                int n = 1;
                while(n <= 10)
                {
                    Console.WriteLine("{0} iterator", n);
                    int count = 0;

                    // Bag에서 데이터 읽기
                    foreach(int i in bag)
                    {
                        Console.WriteLine(i);
                        count++;
                    }
                    Console.WriteLine("Count={0}", count);
                    Thread.Sleep(1000);
                    n++;
                }
            });

            // 두 쓰레드가 끝날 때까지 대기
            Task.WaitAll(t1, t2);
        }
    }
}
