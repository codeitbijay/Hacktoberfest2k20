import java.util.*;
public class MinMax 
{
    public void sort(int arr[],int n){
    int temp;
        for(int i=1;i<n;i++)
        for(int j=0;j<n-i;j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
        }
    }

    
    public static void main (String[] args) {
        Scanner sc=new Scanner(System.in);
        MinMax obj=new MinMax();
        
        System.out.println("Enter the size of an array:");
        int n=sc.nextInt();
        
        if(n>0)
        {
            int[] arr=new int[n];
            
            System.out.println("Enter the elements:");
            for(int i=0;i<n;i++)
            {
                arr[i]=sc.nextInt();
            }
            obj.sort(arr,n);
            System.out.println("MAX:"+arr[n-1]);
            System.out.println("MIN:"+arr[0]);
        }
        else
        {
            System.out.println("Invalid Array Size");
        }
    }
}
