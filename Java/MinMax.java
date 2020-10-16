import java.util.*;
public class MinMax 
{
    int max(int[] arr)
    {
        int max=0;
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        return max;
    }
    
    int min(int[] arr)
    {
        int min=arr[0];
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]<min)
            {
                min=arr[i];
            }
        }
        return min;
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
            
            System.out.println("MAX:"+obj.max(arr));
            System.out.println("MIN:"+obj.max(arr));
        }
        else
        {
            System.out.println("Invalid Array Size");
        }
    }
}
