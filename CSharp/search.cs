//Q-7 WAP to store the numbers in an array and search for a particular number and their occurrences in that.(number of times)

using System;

namespace Lab_11_09_2020
{
    class search_element
    { 
    	void search(int[] arr, int num)
        {
            int count = 0;
            for (int i = 0; i < 10; i++)
                if (arr[i] == num)
                    count++;
            if (count > 0)
                Console.WriteLine("Element found " + count + " times in the string.");
            else
                Console.WriteLine("Element not found.");
        }
        static void Main(String[] args)
        {
            string str;
            int temp;
            int[] arr = new int[10];
            Console.WriteLine("Enter 10 Elements of Array:- ");
            for (int i = 0; i < 10; i++)
            {
                str = Console.ReadLine();
                arr[i] = Convert.ToInt32(str);
            }
            do
            {
                Console.Write("\nEnter the element to be Searched:- ");
                str = Console.ReadLine();
                int num = Convert.ToInt32(str);
                search_element se = new search_element();
                se.search(arr, num);
                Console.Write("Search More? 1 for Yes, 0 for No:-  ");
                temp = Convert.ToInt32(Console.ReadLine());
            } while (temp == 1);
            Console.WriteLine("Exited!!");
            Console.ReadKey();
        }
    }
}
