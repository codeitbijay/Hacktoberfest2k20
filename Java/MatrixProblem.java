import java.util.*;
public class MatrixProblem {
	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter rows of matrix : ");
		int r = sc.nextInt();
		System.out.print("Enter colums of matrix : ");
		int c = sc.nextInt();
		int matrix[][]=new int[r][c];
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				matrix[i][j] = sc.nextInt();
		int sumOfRow[]=new int[r];
		Arrays.fill(sumOfRow, 0);
		int sumOfCol[]=new int[c];
		Arrays.fill(sumOfCol, 0);
		int grandTotal =0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				sumOfRow[i]+=matrix[i][j];
				sumOfCol[j]+=matrix[i][j];	
			}
			grandTotal+=sumOfRow[i];
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				System.out.print(matrix[i][j]+"\t");
			}
			System.out.print("| "+sumOfRow[i]+" \n");
		}
		for(int j=0;j<c;j++){
			System.out.print("----\t");
		}
		System.out.println("----");
		for(int j=0;j<c;j++){
			System.out.print(sumOfCol[j]+"\t");
		}
		System.out.print("| "+grandTotal+"\t");
	}
}
