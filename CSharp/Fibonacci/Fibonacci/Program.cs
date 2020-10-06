using System;

namespace Fibonacci
{
    public class Program
    {
        public static int Fibonacci(int n)
        {
            var a = 0;
            var b = 1;
            // In N steps compute Fibonacci sequence iteratively.
            for (var i = 0; i < n; i++)
            {
                var temp = a;
                a = b;
                b = temp + b;
            }
            return a;
        }

        private static void Main()
        {
            for (var i = 0; i < 15; i++)
            {
                Console.WriteLine(Fibonacci(i));
            }
        }
    }
}