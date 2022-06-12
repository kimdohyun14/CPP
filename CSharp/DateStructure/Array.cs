using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
    /* Array(배열)
     * - 연속적인 메모리 상에 동일한 타입(혹은 그의 파생 타입)의 요소를 일렬로 저장하는 자료구조
     * - 배열 요소는 Index를 사용해서 직접적으로 액세스가 가능하다. O(1)
     * - 다만, 배열은 고정된 크기를 가지기 때문에 크기를 변경하고자 하면 O(N) 이 걸리게 된다.
     * 
     * - 정렬되지 않은 배열에서 원하는 값을 찾는 방법은 앞에서부터 순회해야 한다. O(N)
     * - 정렬된 배열이라면 이진 탐색을 통해서 O(logN)으로 조회가 가능하다.
     * 
     * 모든 C# 배열은 내부적으로 .NET Framework 의 System.Array에서 파생된 것이므로
     * 상속에 의해 System.Array의 메소드, 프로퍼티를 사용할 수 있다.
     * 
     * 고정된 크기에서 벗어나지 않으면서 빠른 액세스를 요구할 때, 배열이 좋다.
     */
    class Array
    {
        static void Main()
        {
            int[] scores = new int[10];
            scores[0] = 99;
            int val = scores[0];

            ShuffleAndPrint();
        }

        public static void ShuffleAndPrint()
        {
            int sum = 0;
            int[] nums = new int[10];

            Random rand = new Random();
            for(int i = 0; i < nums.Length; i++)
            {
                nums[i] = rand.Next() % 100; // 0 ~ 99
            }

            for(int i = 0; i < nums.Length; i++)
            {
                Console.Write($"{nums[i]} ");
                sum += nums[i];
            }

            Console.WriteLine($"\nSum : {sum}");
        }
    }
}
