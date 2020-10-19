using System;

namespace TotalLegsOnAFarm
{
    public class Program
    {
        private static void Main(string[] args)
        {
            Console.WriteLine("Welcome To The Farm!");
            Console.WriteLine("We have chickens, cows and pigs");
            Console.WriteLine("We need help counting all their legs as we are bulk buying shoes");
            Console.WriteLine(" ");
            var noOfChickens = GetNumberOfAnimal("Chickens");
            var noOfCows = GetNumberOfAnimal("Cows");
            var noOfPigs = GetNumberOfAnimal("Pigs");

            var noOfLegs = CountLegs(noOfChickens, noOfCows, noOfPigs);

            Console.WriteLine($"Total Number Of Legs: {noOfLegs} legs");
            Console.WriteLine(" ");
            Console.WriteLine("Press any key to exit");
            Console.ReadLine();
        }

        private static int GetNumberOfAnimal(string animalToRetrieve)
        {
            Console.WriteLine($"Please enter the amount of {animalToRetrieve} on the farm.");
            var noOfAnimalAsString = Console.ReadLine();
            var noOfAnimal = int.Parse(noOfAnimalAsString ?? "0");

            return noOfAnimal;
        }

        private static int CountLegs(int noOfChickens, int noOfCows, int noOfPigs)
        {
            var chicken = new Chicken(2);
            var cow = new Cow(4);
            var pig = new Pig(4);

            var chickenLegs = noOfChickens * chicken.NoOfLegs;
            var cowLegs = noOfCows * cow.NoOfLegs;
            var pigLegs = noOfPigs * pig.NoOfLegs;
            var noOfLegs = chickenLegs + cowLegs + pigLegs;

            return noOfLegs;
        }
    }

    public class Animal
    {
        public int NoOfLegs { get; set; }

        public Animal(int noOfLegs)
        {
            NoOfLegs = noOfLegs;
        }
    }

    public class Cow : Animal
    {
        public Cow(int noOfLegs) : base(noOfLegs)
        {
        }
    }

    public class Chicken : Animal
    {
        public Chicken(int noOfLegs) : base(noOfLegs)
        {
        }
    }

    public class Pig : Animal
    {
        public Pig(int noOfLegs) : base(noOfLegs)
        {
        }
    }
}