import java.io.*;
import java.util.*;
class CountCharString{
	public static void main(String args[]){
		String word;
		int count=0;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the String Value");
		word=sc.nextLine();
		for(int i=0;i<word.length();i++){
		if(word.charAt(i)!=' '){
			++count;
		}
		}
		System.out.println("The Number of Characters in an String is "+count);
	}
}