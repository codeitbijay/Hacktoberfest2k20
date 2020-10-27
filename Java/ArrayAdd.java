package arrayadd;
import java.util.Random;
import java.util.Scanner;

public class ArrayAdd {
    public static void main(String[] args) {
        Scanner keyboard = new Scanner(System.in);
        Random rand = new Random();
        
        int r,c;
        System.out.print("Enter No Of Rows For The Matrix : ");
        r = keyboard.nextInt();
        System.out.print("Enter No Of Columns For The Matrix : ");
        c = keyboard.nextInt();
        
        int num1[][] = new int[r][c];
        int num2[][] = new int[r][c];
        int sum[][] = new int[r][c];
        
        System.out.println();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                num1[i][j] = rand.nextInt(100)+1;
            }
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                 num2[i][j] = rand.nextInt(100)+1;
            }
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                sum[i][j] = num1[i][j] + num2[i][j];
            }
        }
        
        System.out.println();
        System.out.println("Array 1 : ");
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                System.out.print(num1[i][j]+"\t");
            }
            System.out.println();
        }
        
        System.out.println();
        System.out.println("Array 2 : ");
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                System.out.print(num2[i][j]+"\t");
            }
            System.out.println();
        }
        
        System.out.println();
        System.out.println("Summation Of Both Arrays : ");
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                System.out.print(sum[i][j]+"\t");
            }
            System.out.println();
        }
    }
}
