import java.util.Scanner;

public class BubbleSort {
    public static Scanner scan = new Scanner(System.in);
    public static void main(String[] args){
        System.out.print("Enter the number of items to be sorted: ");
        int n = scan.nextInt();
        int arr[] = new int[n];
        int unsortedArr[] = getArr(arr);
        // SortArr(arr);
        printArr(sortArr(unsortedArr));
    }

    public static int[] getArr(int[] arr){
        for(int i=0; i<arr.length; i++){
            System.out.print("Enter item no. "+(i+1)+" :");
            arr[i] = scan.nextInt();
        }
        return arr;
    }

    public static void printArr(int arr[]){
        for(int item: arr){
            System.out.print(item+" ");
        }
    }

    public static int[] sortArr(int arr[]){
        int arrLen = arr.length;
        for(int i=0; i<arrLen-1; i++){
            for(int j=0; j<arrLen-1; j++){
                if(arr[j+1]<arr[j]){
                    int temp =arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        return arr;
    }
}
