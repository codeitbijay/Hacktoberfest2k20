using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public class WaterWalls
{
    public static long CalculateMaxArea(int[] array)
    {
        long greatestArea = 0;
        if (array != null)
        {
            var frontPointer = 0;
            var backPointer = array.Length - 1;

            while (frontPointer < backPointer)
            {
                long product = backPointer - frontPointer;
                product *= array[frontPointer] <= array[backPointer] ? array[frontPointer] : array[backPointer];

                if (product > greatestArea)
                {
                    greatestArea = product;
                }

                if (array[frontPointer] <= array[backPointer])
                {
                    frontPointer++;
                }
                else
                {
                    backPointer--;
                }
            }
        }
        return greatestArea;
    }
}
