import java.io.*;
import java.util.*;
import java.lang.*;

class GFG{

	public static void main(String[] args)throws java.lang.Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		while(t-->0){
            String str1 = br.readLine().trim();    
			long num = Long.parseLong(str1);
			//Taking long to handle 92289736129
			//System.out.println(num);
			//while(num%10 == 0)
			//    num=num/10;
			//System.out.println(num);
			String str = Long.toString(num);    
			int i=0;
			
			boolean flag = false;
			int n = str.length();
			int HM[] = new int[10];
			for(i=0;i<n;i++){
				HM[str.charAt(i)-'0']++;

				if(HM[str.charAt(i)-'0'] >1 || str.charAt(i) == '0' || str.charAt(i) == '1' || (HM[2]>0 && HM[3]>0 && HM[6]>0) || (HM[2]>0 && HM[4]>0 && HM[8]>0 )){
					flag = true;
					break;
					}
				}
			if(!flag)
				System.out.println("1");
			else
				System.out.println("0");
		}
	}
}
