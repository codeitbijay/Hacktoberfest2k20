using System;
public class Demo {
   public static void Main(string[] args) {
      int val1 = 0, val2 = 1, val3, i, n;
      n = 7;
      Console.WriteLine("Fibonacci series:");
      Console.Write(val1+" "+val2+" ");
      for(i=2;i<n;++i) {
         val3 = val1 + val2;
         Console.Write(val3+" ");
         val1 = val2;
         val2 = val3;
      }
   }
}
