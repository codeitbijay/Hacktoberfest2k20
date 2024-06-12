import java.util.Scanner; 
public class guessnumber { 
    public static void
    guessingNumberGame() 
    { 
        Scanner sc = new Scanner(System.in); 
        int secretnumber = 1 + (int)(20*Math.random()); 
        int i=0, guess; 
        System.out.println( "A number is chosen between 1 to 20"); 
        System.out.println( "Guess it in  within 5 trials."); 

        while(i<5){ 
            System.out.println( "Guess the number:"); 
            guess = sc.nextInt(); 
            if(guess>20 || guess<1){
                System.out.println("please choose a number in the range");
                continue;
            }
            else if (secretnumber == guess) { 
                System.out.println( "You guessed the number"); 
                break; 
            } 
            else if (secretnumber > guess && i != 4) { 
                System.out.println( "The number is greater than " + guess); 

            } 
            else if (secretnumber < guess && i != 4) { 
                System.out.println( "The number is less than " + guess); 
            } 
            i++;
        } 
        System.out.println( "The secret number was " + secretnumber); 
        
    } 
    public static void main(String arg[]) 
    { 
        guessingNumberGame(); 
    } 
}