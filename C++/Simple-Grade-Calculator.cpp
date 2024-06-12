#include<stdio.h>
#include<conio.h>
main()
{
	printf("________________________________________________________________________________");
	printf("\n                             This program is created by\n");
	printf("\n                               Mr. Siriwat Wongpan\n");
	printf("\n                             Grade 11 room 1 Number 11\n");
	printf("\n________________________________________________________________________________\n\n");
		
	
	char na[20],su[20],idnum[20];
	float test1,test2,test3,test4,total;
	
	printf("                     Your name is                           = ");
		gets(&na[20]); 
	printf("                     Your surname is                        = ");
		gets(&su[20]); 
	printf("                     Your student ID is                     = ");
		gets(&idnum[20]);
	printf("                     Input your before midterm score        = ");
		scanf("%f",&test1);
	printf("                     Input your midterm score               = ");
		scanf("%f",&test2); 
	printf("                     Input your after midterm score         = ");
		scanf("%f",&test3); 
	printf("                     Input your Final score                 = ");
		scanf("%f",&test4); 

	total=test1+test2+test3+test4;
	
	printf("\n       -------------------------------------------------------------------       \n");

	printf("                     Your name is                           = "),puts(&na[20]);
	printf("                     Your surname is                        = "),puts(&su[20]);
	printf("                     Your student ID is                     = "),puts(&idnum[20]);
	printf("\n                     Your before midterm score is           = %.2f",test1);
	printf("\n                     Your midterm score is                  = %.2f",test2);
	printf("\n                     Your after midterm score is            = %.2f",test3);
	printf("\n                     Your Final score is                    = %.2f",test4);
	printf("\n                     Your total score is                    = %.2f\n",total);
	
	
	
	if(total>=80)
	{
		printf("\n 			     > Your study level = 4 <  ");
	} 



	else if(total>=75)
	{
		printf("\n 			    > Your study level = 3.5 < ");
	} 
	
	

      else if(total>=70)
	{
		printf("\n 			    > Your study level = 3 < ");
    } 
	
	
	else if(total>=65)
	{
		printf("\n 			    > Your study level = 2.5 < ");
	} 
	
	
	else if(total>=60)
	{
		printf("\n 			    > Your study level = 2 < ");
	}
	
	
	else if(total>=55)
	{
		printf("\n 			    > Your study level = 1.5 < ");
	}
	
	
	else if(total>=50)
	{
		printf("\n 			    > Your study level = 1 < ");
	}
	
	
	else 
	{
		printf("\n 			    > Your study level = 0 < ");
	}

		
	
	printf("\n\n\n\n___________________________________ The end ____________________________________\n");

   
   
   
   
   
	getch();
}