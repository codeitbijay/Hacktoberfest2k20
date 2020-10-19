using System;

namespace TravelingSalesmen
{
    public class City
    {
        private static readonly Random Random = new Random();

        public City(int cityName)
        {
            X = Random.NextDouble() * 100;
            Y = Random.NextDouble() * 100;
            CityName = cityName;
        }

        public double X { get; }

        public double Y { get; }

        public int CityName { get; }
    }
}