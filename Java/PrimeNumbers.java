import java.util.Scanner;
public class PrimeNumbers
{
    public static void main (String[] args) {
        int flag=0;
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        System.out.println();
        if(a>=b||a<1||b<1)
        {
            System.out.println("Provide valid input");
        }
        else
        {
            for(int i=a;i<=b;i++)
            {
                for(int j=2;j<i;j++)
                {
                    if(i%j==0)
                    {
                        flag++;
                    }
                }
                if(flag==0)
                {
                    if(i!=1)
                    {
                        System.out.print(i+" ");
                    }
                }
                flag=0;
                
            }
        }
    }
}
