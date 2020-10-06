using System;
using System.Collections.Generic;
using System.Linq;

namespace TravelingSalesmen
{
    internal static class Program
    {
        private static void Main(string[] args)
        {
            Console.WriteLine("Please enter the number of stops, they will be randomly placed on a virtual map");
            var noOfStops = Convert.ToInt32(Console.ReadLine());

            var stops = Enumerable.Range(1, noOfStops)
                                  .Select(i => new Stop(new City(i)))
                                  .NearestNeighbors()
                                  .ToList();

            stops.Connect(true);

            var startingTour = new Tour(stops);

            while (true)
            {
                Console.WriteLine(startingTour);

                var newTour = startingTour.GenerateMutations()
                                          .MinBy(tour => tour.Cost());

                if (newTour.Cost() < startingTour.Cost())
                {
                    startingTour = newTour;
                }
                else
                {
                    break;
                }
            }

            Console.ReadLine();
        }

        public static void Connect(this IEnumerable<Stop> stops, bool loop)
        {
            Stop prev = null, first = null;
            foreach (var stop in stops)
            {
                first ??= stop;
                if (prev != null)
                {
                    prev.Next = stop;
                }

                prev = stop;
            }

            if (!loop)
            {
                return;
            }
            if (prev != null)
            {
                prev.Next = first;
            }
        }

        private static T MinBy<T, TComparable>(
            this IEnumerable<T> xs,
            Func<T, TComparable> func)
            where TComparable : IComparable<TComparable>
        {
            return xs.DefaultIfEmpty().Aggregate(
                (maxSoFar, elem) =>
                func(elem).CompareTo(func(maxSoFar)) > 0 ? maxSoFar : elem);
        }

        private static IEnumerable<Stop> NearestNeighbors(this IEnumerable<Stop> stops)
        {
            var stopsLeft = stops.ToList();
            for (var stop = stopsLeft.First();
                 stop != null;
                 stop = stopsLeft.MinBy(s => Stop.Distance(stop, s)))
            {
                stopsLeft.Remove(stop);
                yield return stop;
            }
        }
    }
}