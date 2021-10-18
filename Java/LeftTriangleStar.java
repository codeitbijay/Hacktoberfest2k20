//left Triangle star
import java.io.*;
import java.util.*;
class LeftTriangleStar{
	public static void main(String args[]){
		int i,j,n;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the N value");
		n=sc.nextInt();
		for(i=0;i<n;i++){
			for(j=0;j<i+1;j++){
				System.out.print("*");
				System.out.print("\t");
			}
			System.out.println(" ");
		}
	}
}
		
		