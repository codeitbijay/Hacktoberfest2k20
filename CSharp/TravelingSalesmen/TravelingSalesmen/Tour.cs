using System.Collections.Generic;
using System.Linq;

namespace TravelingSalesmen
{
    public class Tour
    {
        public Tour(IEnumerable<Stop> stops)
        {
            Anchor = stops.First();
        }

        public IEnumerable<Tour> GenerateMutations()
        {
            for (var stop = Anchor; !Equals(stop.Next, Anchor); stop = stop.Next)
            {
                //skip the next one, since you can't swap with that
                var current = stop.Next.Next;
                while (!Equals(current, Anchor))
                {
                    yield return CloneWithSwap(stop.City, current.City);
                    current = current.Next;
                }
            }
        }

        private Stop Anchor { get; set; }

        private Tour CloneWithSwap(City firstCity, City secondCity)
        {
            Stop firstFrom = null, secondFrom = null;
            var stops = UnconnectedClones();
            stops.Connect(true);

            foreach (var stop in stops)
            {
                if (stop.City == firstCity) firstFrom = stop;

                if (stop.City == secondCity) secondFrom = stop;
            }

            if (firstFrom != null)
            {
                var firstTo = firstFrom.Next;
                if (secondFrom != null)
                {
                    var secondTo = secondFrom.Next;

                    firstTo.CanGetTo()
                        .TakeWhile(stop => !Equals(stop, secondTo))
                        .Reverse()
                        .Connect(false);

                    firstTo.Next = secondTo;
                }
            }

            if (firstFrom != null)
            {
                firstFrom.Next = secondFrom;
            }

            var tour = new Tour(stops);
            return tour;
        }

        private IList<Stop> UnconnectedClones()
        {
            return Cycle().Select(stop => stop.Clone()).ToList();
        }

        public double Cost()
        {
            return Cycle().Aggregate(
                0.0,
                (sum, stop) =>
                sum + Stop.Distance(stop, stop.Next));
        }

        private IEnumerable<Stop> Cycle()
        {
            return Anchor.CanGetTo();
        }

        public override string ToString()
        {
            var path = string.Join(
                "->",
                Cycle().Select(stop => stop.ToString()).ToArray());
            return $"Cost: {Cost()}, Path:{path}";
        }
    }
}