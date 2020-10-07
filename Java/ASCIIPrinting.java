
//  This program creates an ASCII art Space Needle

public class SpaceNeedle {
	
	//Creates a constant controlling the size of the needle
	public static final int SIZE = 3;
	
	//prints out the space needle's different sections
	public static void main(String[] args) {
        tip();
        topHalf();
        bottomHalf();
        tip();
        body();
        topHalf();
	}
	
	//prints out the very tip of the needle
	//this is also used in the middle area
    public static void tip() {
    	
        for(int tip = 1; tip <= SIZE; tip++) {        	
            for(int spaces = 1; spaces <= SIZE*3; spaces++) {            	
                System.out.print(" ");
            }            
            System.out.println("||");            
        }
    }
    
    //prints out the top half of the upper part of the space needle
    //this is also used on the bottom
    public static void topHalf() {
    	
        for( int i = 1; i <= SIZE; i++){
            for(int spaces = 1; spaces <= 3*SIZE - 3*i; spaces++) {
                System.out.print(" "); 
            }
            
            for(int j = 1; j <= 1; j++) {
                System.out.print("__/");
            }
            
            for(int j = 1; j <= i - 1; j++) {
                System.out.print(":::");
            }
            
            System.out.print("||");
            
            for(int j = 1; j <= i - 1; j++) {
                System.out.print(":::");
            }
            
            for(int j = 1; j <= 1; j++) {
                System.out.print("\\__");
            }
            
            System.out.println();
        }
        
        System.out.print("|");
        
        for(int i = 1; i <= 6 * SIZE; i++) {
            System.out.print("\"");
        }
        
        System.out.println("|");
    }
    
    //prints out the bottom half of the upper part of the space needle
    public static void bottomHalf() {

          for(int i = 1; i <= SIZE; i++) {
              for(int j = 1; j <= i - 1; j++) {
                  System.out.print("  ");
              }
              
	          System.out.print("\\_");
	          for(int j = 3*SIZE-i; j >= i; j--) {
	              System.out.print("/\\");
	          }
	          System.out.println("_/");
          }
    }
    
    //prints out the body of the needle where there are percent signs
    public static void body() {
    	for(int i = 1; i <= SIZE*SIZE; i++) {
            for(int j = 1; j <= 3*SIZE-(SIZE-1); j++) {
                System.out.print(" ");
            }
            
            System.out.print("|");
            for(int j = 1; j <= SIZE-2; j++) {
            	System.out.print("%");
            }
            System.out.print("||");
            for(int j = 1; j <= SIZE-2; j++) {
            	System.out.print("%");
            }
            System.out.print("|");
            
            System.out.println();
        }
    }
}
