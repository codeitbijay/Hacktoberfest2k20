import java.util.Scanner;
public class Solution
{
    public static void TowerofHanoi(int n, String source, String dest, String aux) {
        // Base Case
        if (n == 1) {
            System.out.println("Move disk 1 from " + source + " to " + dest);
            return;
        }
        // Move (n-1) disks from source to aux.
        TowerofHanoi(n - 1, source, aux, dest);
        // Move nth disk from source to dest.
        System.out.println("Move disk " + n + " from " + source + " to " + dest);
        // Move (n-1) disks from aux to dest.
        TowerofHanoi(n - 1, aux, dest, source);
    }

    public static void main(String args[]) {
        while (1 > 0) {
            Scanner sc = new Scanner(System.in);
            System.out.println("Please Enter Number of Disks");
            int n = sc.nextInt();
            TowerofHanoi(n, "source", "dest", "aux");
        }

    }
}