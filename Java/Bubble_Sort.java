//Program to sort the Array using Bubble Sort Technique
import java.util.Scanner;
class Bubble_Sort
{
    // function for bubble sort
    public static void BubbleSort(int[] array, int size)
    {
        int temp;

        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j] > array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    // function ro print array
    public static void Print_Array(int[] array, int size)
    {
        for (int i = 0; i < size; i++)
            System.out.print(array[i] + " ");

        System.out.println();
    }

    public static void main(String[] args)
    {
		//create Scnner object to read the input
		Scanner sc=new Scanner(System.in);
		int len=sc.nextInt();
		
		//define an array to store the elements
        int[] array =new int[len];
		
		//read the elements and store it in an array 
		for(int i=0;i<len;i++)
			array[i]=sc.nextInt();
		
		//call the method to sort the array 
        BubbleSort(array, len);
		
		//print the sorted array 
        Print_Array(array, len);
    }
}
//Input 
//7
//5 3 4 1 3 2 7
// Output
// 1 2 3 3 4 5 7

