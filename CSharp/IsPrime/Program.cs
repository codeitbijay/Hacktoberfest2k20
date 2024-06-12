using System;

namespace IsPrime
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Input a number:");
            var input=Console.ReadLine();
            var number = Convert.ToInt64(input);
            var isPrime = IsPrime(number);
            Console.WriteLine(isPrime ? $"{number} is a Prime number." : $"{number} is not a Prime number.");
            Console.ReadLine();
        }

        public static bool IsPrime(long num)
        {
            if (num <= 1) return false;
            if (num == 2) return true;
            if (num % 2 == 0) return false;

            var mid = (int)Math.Floor((Math.Sqrt(num)));

            for (int i = 3; i <= mid; i += 2)
            {
                if ((num % i) == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
