//Q-8 Write a program to implement Jagged  Arrays.(Print any pattern)

using System;

namespace Lab_11_09_2020
{
    class jagged
    {
        public static void Main(String[] args)
        {
            int i = 0, j = 0;
            int k = 1, n = 2, m = 0;
            Console.Write("Enter Number of Rows:- ");
            m = Convert.ToInt32(Console.ReadLine());
            int[][] arr = new int[m][];
            for (i = 0; i < arr.Length; i++)
            {
                arr[i] = new int[i + 1];
                for (j = 0; j < arr[i].Length; j++)
                {
                    if ((i + 1) % 2 != 0)
                    {
                        arr[i][j] = k;
                        k = k + 2;
                    }
                    else
                    {
                        arr[i][j] = n;
                        n += 2;
                    }
                }
            }
            for (i = 0; i < arr.Length; i++)
            {
                for (j = 0; j < arr[i].Length; j++)
                {
                    Console.Write(arr[i][j] + " ");
                }
                Console.Write("\n");
            }
            Console.ReadKey();
        }
    }
}