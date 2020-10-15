//Q-4 Write a C# Program to implement to Convert Decimal to Binary, Octal, Hexadecimal and reverse too.

using System;
using System.IO;

namespace Lab_11_09_2020
{
    class Conversion
    {
        static void Main(string[] args)
        {
            int a;
            double n, b, o, h, bd, od, hd;
            while (true)
            {
                Console.WriteLine("==== Number Conversions ====");
                Console.WriteLine("  1.Decimal to Binary,Octal,Hexadecimal");
                Console.WriteLine("  2.Binary to Decimal");
                Console.WriteLine("  3.Octal to Decimal");
                Console.WriteLine("  4.HexaDecimal to Decimal");
                Console.WriteLine("  5.Exit");
                Console.Write(" Enter Choice:-  ");
                a = Convert.ToInt32(Console.ReadLine());
            
                switch (a)
                {
                    case 1:
                        Console.Write(" Enter Number in Decimal Form:-  ");
                        n = Math.Truncate(double.Parse(Console.ReadLine()));
                        b = Math.Truncate(convert_decimal_binary(n));
                        o = Math.Truncate(convert_decimal_octal(n));
                        h = Math.Truncate(convert_decimal_hexadecimal(n));
                        break;
                    case 2:
                        Console.Write(" Enter Number in Binary Form:-  ");
                        n = Math.Truncate(double.Parse(Console.ReadLine()));
                        bd = Math.Truncate(convert_binary_decimal(n));
                        break;
                    case 3:
                        Console.Write(" Enter Number in Octal Form:-  ");
                        n = Math.Truncate(double.Parse(Console.ReadLine()));
                        od = Math.Truncate(convert_octal_decimal(n));
                        break;
                    case 4:
                        Console.Write(" Enter Number in Hexadecimal Form;-  ");
                        n = Math.Truncate(double.Parse(Console.ReadLine()));
                        hd = Math.Truncate(convert_hexadecimal_decimal(n));
                        break;
                    case 5:
                        Console.WriteLine("Exited!!");
                        goto end;
                        break;
                    default:
                        Console.WriteLine("Wrong Option");
                        break;
                }
            }
            end:
            Console.ReadKey();
        }

        static double convert_decimal_binary(double x)
        {
            double c = Math.Truncate(x);
            double y, z;
            string s = null;
            while (c != 0)
            {
                y = Math.Truncate(c % 2);
                s = y.ToString() + s;
                c = Math.Truncate(c / 2);
            }
            Console.WriteLine("\n Binary Equivalent is " + s);
            z = Math.Truncate(Convert.ToDouble(s));
            return z;
        }
        static double convert_decimal_octal(double x)
        {
            double c = Math.Truncate(x);
            double y, z;
            string s = null;
            while (c != 0)
            {
                y = Math.Truncate(c % 8);
                s = y.ToString() + s;
                c = Math.Truncate(c / 8);
            }
            Console.WriteLine(" Octal Equivalent is " + s);
            z = Math.Truncate(Convert.ToDouble(s));
            return z;
        }
        static double convert_decimal_hexadecimal(double x)
        {
            double c = Math.Truncate(x);
            double y;
            string s = null;
            while (c != 0)
            {
                y = Math.Truncate(c % 16);
                if (y == 10)
                    s = 'A' + s;
                else if (y == 11)
                    s = 'B' + s;
                else if (y == 12)
                    s = 'C' + s;
                else if (y == 13)
                    s = 'D' + s;
                else if (y == 14)
                    s = 'E' + s;
                else if (y == 15)
                    s = 'F' + s;
                else
                    s = y.ToString() + s;
                c = Math.Truncate(c / 16);
            }
            Console.WriteLine(" Hexadecimal Equivalent is " + s);
            return 0;
        }
        static double convert_binary_decimal(double x)
        {
            int Count = 0;
            double c = Math.Truncate(x);
            double y, sum = 0;
            while (c != 0)
            {
                y = Math.Truncate(c % 10);
                y = Math.Truncate((Math.Pow(2, Count)) * y);
                sum = Math.Truncate(sum + y);
                Count++;
            }
            Console.WriteLine("\n Decimal Equivalent is " + sum);
            return 0;
        }
        static double convert_octal_decimal(double x)
        {
            int Count = 0;
            double c = Math.Truncate(x);
            double y, sum = 0;
            while (c != 0)
            {
                y = Math.Truncate(c % 10);
                y = Math.Truncate((Math.Pow(8, Count)) * y);
                sum = Math.Truncate(sum + y);
                Count++;
            }
            Console.WriteLine("\n Decimal Equivalent is " + sum);
            return 0;
        }
        static double convert_hexadecimal_decimal(double x)
        {
            int Count = 0;
            double c = Math.Truncate(x);
            double y, sum = 0;
            while (c != 0)
            {
                y = Math.Truncate(c % 10);
                y = Math.Truncate((Math.Pow(16, Count)) * y);
                sum = Math.Truncate(sum + y);
                Count++;
            }
            Console.WriteLine("\n Decimal Equivalent is " + sum);
            return 0;
        }
    }
}