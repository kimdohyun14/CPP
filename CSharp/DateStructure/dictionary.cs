using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dictionary
{
    /*
     * Dictionary<TKey,TValue>
     * 해시 테이블로 구현되어 있기 때문에 값을 검색하는 것은 매우 빠르다. O(1)
     * 다만, 검색 속도는 지정된 형식 Key의 해시 알고리즘 품질에 따라 달라진다.
     * 
     * Key는 null 수 없지만 해당 형식이 참조 형식 TValue인 경우엔 값이 될 수 있다.
     * 
     * 주요 속성)
     * Comparer : 사전에 대한 키의 이맃 여부를 확인하는 데 사용되는 IEqualityComparer<T>를 가져온다.
     * Count : 키/값 쌍의 수
     * Item[TKey] : 지정된 키에 연결된 값을 가져오거나 설정한다. O(1)
     * Keys : 키를 포함하는 컬렉션을 가져온다.
     * Values : 값을 포함하는 컬렉션을 가져온다.
     * 
     * 주요 메서드)
     * ContainsKey(TKey) : 지정한 키가 포함되어 있는지 여부를 확인
     * ContainsValue(TValue) : 특정 값이 들어 있는지 여부를 확인
     * GetEnumerator() : Dictionary<TKey,TValue> 를 반복하는 열거자를 반환한다.
     * GetType() : 현재 인스턴스의 Type을 가져온다.
     * TryGetValue(TKey,TValue) : 지정한 키와 연결된 값을 가져온다. O(1) => 사전에 없는 키에 자주 액세스하려고 시도하는 경우 이 메서드를 사용한다.
     */
    class Program
    {
        static void Main(string[] args)
        {
            Dictionary<string, string> openWith = new Dictionary<string, string>();

            // Key Unique
            // Value Not Unique
            openWith.Add("txt", "notepad.exe");
            openWith.Add("bmp,", "paint.exe");
            openWith.Add("dib", "paint.exe");
            openWith.Add("rtf", "wordpad.exe");

            // try-catch 문은 성능을 많이 잡아먹기 때문에
            // 정말로 필요한 곳에서만 사용하자.
            try
            {
                openWith.Add("txt", "22");
            }
            catch (ArgumentException)
            {
                Console.WriteLine("key already exists");
            }

            // indexer 를 이용해서 우리는 value를 변경할 수 있다.
            Console.WriteLine($"Key : rft, Value : {openWith["rtf"]}");
            openWith["rtf"] = "window.exe";
            Console.WriteLine($"Key : rft, Value : {openWith["rtf"]}");

            // 단, 등록된 Key 가 없는데 접근하려고 하면 error
            try
            {
                Console.WriteLine($"Key : AAA, Value : {openWith["AAA"]}");
            }
            catch (KeyNotFoundException)
            {
                Console.WriteLine("AAA key is not Found");
            }

            // value 검색하는 방법
            string value;
            if (openWith.TryGetValue("rtf", out value))
            {
                Console.WriteLine($"For Key = \"rtf\", value = {value}");
            }
            else
            {
                Console.WriteLine($"Key = \"rtf\" is not found.");
            }

            // Key 검색, 없으면 추가
            if (!openWith.ContainsKey("ht"))
            {
                openWith.Add("ht", "hypertrm.exe");
            }

            Console.WriteLine();
            // element 순회하는 방법 (key-value 쌍)
            foreach(KeyValuePair<string, string> kvp in openWith)
            {
                Console.WriteLine($"Key = {kvp.Key}, Value = {kvp.Value}");
            }

            Dictionary<string, string>.ValueCollection valueColl = openWith.Values;
            Console.WriteLine();
            foreach(string s in valueColl)
            {
                Console.WriteLine("Value = {0}", s);
            }

            Dictionary<string, string>.KeyCollection keyColl = openWith.Keys;
            Console.WriteLine();
            foreach(string s in keyColl)
            {
                Console.WriteLine("Key = {0}", s);
            }

            Console.WriteLine();
            // Remove (없는 키를 삭제하는 건 문제가 없다.)
            openWith.Remove("doc");
            if (!openWith.ContainsKey("doc"))
            {
                Console.WriteLine("Key \"doc\" is not found.");
            }

            // Null 이라는 키도 집어넣을 수 있을까? => 허용되지 않는다.
            //openWith.Add(null, "null!!");

            //foreach(var kvp in openWith)
            //{
            //    Console.WriteLine($"Key : {kvp.Key}, Value : {kvp.Value}");
            //}

            Console.WriteLine($"Type : {openWith.GetType()}");
        }
    }
}
