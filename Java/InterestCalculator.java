/* 
 * This program takes inputs (Investment; Interest Rate; Annual Deposit; Time) 
 * and use them to create a table the you can use to tell the total amount of interest over a period of time
 */

import java.util.*;
public class Interest {

	public static void main(String[] args) {
		//initializes the scanner object
		Scanner scanner = new Scanner(System.in);
		//Sets variables to the inputs
		double investment = inputFinder(scanner, "Enter your initial investment:");
		double annualDeposit = inputFinder(scanner, "Enter your annual deposit: ");
		int years = (int)inputFinder(scanner, "Enter number of Years: ");
		double interestRate = inputFinder(scanner, "Enter interest rate: ");
		
		//calls method printTable
		printTable(investment, annualDeposit, years, interestRate);
		
		//closes scanner
		scanner.close();
	}
	
	//prints the prompt and asks for the input
	public static double inputFinder(Scanner scanner, String message) {
		System.out.println(message);
		return scanner.nextDouble();
	}
	
	
	//Prints the table 
	public static void printTable(double investment, double annualDeposit, int years, double interestRate) {
		//prints some whitespace
		System.out.println(); 
		System.out.println(); 
		System.out.println();
		
		/* we set the total to how much we invested because that is how much we have total right after depositing
		 */
		double total = investment;
		
		
		//prints the headers
 		System.out.print("Year");
 		spaces("Year", 7);
 		
 		
 		System.out.print("Interest");
 		spaces("Interest", 10);
 		
 		
 		System.out.print("Deposit");
 		spaces("Deposit", 10);
 		
 		
 		System.out.println("Balance");
 		
 		//next line
		System.out.print("start");
		spaces("start", 27);
		
		
		System.out.println(total);
		
		
		
		/* the rest of this method calculates the values needed to be printed and then prints them into the table format
		 */
		for(int afterYears = 1; afterYears <= years; afterYears++) {
			
			
			//calculate the amount of money added from interest
			double interest = (int) (((interestRate/100) * total) * 100.0) / 100.0;
			
			//calculate the total based on current
			total = (int) ((total + interest + annualDeposit) * 100.0) / 100.0;
			
			//prints out the rows for the table
			System.out.print(afterYears);
			spaces("" + afterYears, 7); 
			System.out.print(interest);
			spaces("" + interest, 10);
			System.out.print(annualDeposit);
			spaces("" + annualDeposit, 10);
			System.out.print(total);
			
			System.out.println();
		}		
	}
	
	
 /* This is a method that let replicates the \t for strings except instead of 8 characters per tab, I can use however many I need.
	* 
	* I understand that this code is not necessary, however, I feel it makes the program look neater and it can make the program more reusable for different purposes
	*/
	public static void spaces(String currentCharcaters, int charactersWanted) {
		int spacesNeeded = charactersWanted - currentCharcaters.length();
		for(int i = 1; i <= spacesNeeded; i++) {
			System.out.print(" ");
		}
	}
}

