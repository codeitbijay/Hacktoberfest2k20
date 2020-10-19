import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class Palindrome 
{
    public static void main (String[] args) {
        Scanner sc= new Scanner(System.in);
        
        System.out.println("Enter the word :");
        String str=sc.nextLine();
        int len=str.length();
        
        Pattern p=Pattern.compile("[^a-z0-9]", Pattern.CASE_INSENSITIVE);
        Matcher m=p.matcher(str);
        boolean b=m.find();
       
        if(b)
        {
            System.out.println("Invalid Input");
        }
        else
        {
            String rvs=new String();
            
            for(int i=(len-1); i>=0; i--)
            {
                rvs=rvs+str.charAt(i);
            }
            
            if(str.equalsIgnoreCase(rvs))
            {
                System.out.println(str+" is a Palindrome");
            }
            else
            {
                System.out.println(str+" is not a Palindrome");
            }
        }
    }
}
