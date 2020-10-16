using System;

namespace InputOutput
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Welcome to the C# input output example.");
            Console.WriteLine("Please enter your name to see how input works:");
            var name = Console.ReadLine();
            Console.WriteLine("");
            // This is string interpolation in C#
            Console.WriteLine($"Hello, {name}");
            Console.WriteLine("");
            Console.WriteLine("Press Any Key To Exit");
            Console.ReadLine();
        }
    }
}