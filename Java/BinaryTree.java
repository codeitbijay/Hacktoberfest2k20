/*

	Title	:	To implement binary tree and perform recursive and non-recursive traversals on it.
	
*/

import java.util.Scanner;
import java.util.Stack;

class node
{
	int data;
	node lc,rc;
	
	node(int nm)
	{
		data=nm;
		lc=null;
		rc=null;
	}
}

class tree
{
	private node root;
	
	tree()
	{
		root=null;
	}
	
	void create()
	{
		int flag=0;
		int nm;
		char ch;
		
		Scanner sc=new Scanner(System.in);
		
		do
		{
			flag=0;
			
			System.out.println("Enter the node: ");
			nm=sc.nextInt();
			
			node temp= new node(nm);
			
			if(root==null)
			{
				root=temp;
				flag=1;
			}
			else
			{
				char dir;
				node ptr=root;
				
				
				while(flag==0)
				{
					System.out.println("\n"+ptr.data);
					System.out.println("Enter the direction: (L/R)");
					dir=sc.next().charAt(0);
					
					if(dir=='l'||dir=='L')
					{
						if(ptr.lc!=null)
							ptr=ptr.lc;
						else
						{
							ptr.lc=temp;
							flag=1;
						}
						
					}
					else if(dir=='r'||dir=='R')
					{
						if(ptr.rc!=null)
							ptr=ptr.rc;
						else
						{
							ptr.rc=temp;
							flag=1;
						}
					}
					else
						System.out.println("Invalid direction!");
					
				}
			}
			
			if(flag==1)
				System.out.println("Node inserted!");
			
			
			System.out.println("\n\nDo you want to continue creating? (Y/N)");
			ch=sc.next().charAt(0);
			
		}while(ch=='y'||ch=='Y');
				
	
	}
	
	void inorder(node local_root)
	{
		if(local_root!=null)
		{
			inorder(local_root.lc);
			System.out.println(local_root.data);
			inorder(local_root.rc);
		}
	}
	
	void preorder(node local_root)
	{
		if(local_root!=null)
		{
			System.out.println(local_root.data);
			preorder(local_root.lc);			
			preorder(local_root.rc);
		}
	}
	
	void postorder(node local_root)
	{
		if(local_root!=null)
		{
			postorder(local_root.lc);
			postorder(local_root.rc);
			System.out.println(local_root.data);
		}
	}
	
	
	void r_inorder()
	{
		inorder(root);
	}
	
	void r_preorder()
	{
		preorder(root);
	}
	
	void r_postorder()
	{
		postorder(root);
	}
	
	void nr_inorder() 
	{
		
		node ptr=root;
		Stack<node> s=new Stack<node>();
		
		while(true)
		{
			while(ptr!=null)
			{
				s.push(ptr);
				ptr=ptr.lc;
			}
			
			if(s.isEmpty())
				break;
			
			ptr=s.pop();
			System.out.println(ptr.data);
			ptr=ptr.rc;			
			
		}
	}
	
	void nr_preorder() 
	{
		node ptr=root;
		Stack<node> s=new Stack<node>();
		
		while(true)
		{
			while(ptr!=null)
			{
				System.out.println(ptr.data);
				s.push(ptr);
				ptr=ptr.lc;
			}
			
			if(s.isEmpty())
				return;
			
			ptr=s.pop();
			ptr=ptr.rc;
			
			
		}
	}
	
	void nr_postorder()
	{

		Stack <node> s=new Stack<node>();
		Stack<Character> s1=new Stack<Character> ();

	    node ptr=root; 
		char flag;
	       
	      	while(!s.isEmpty()||ptr!=null)
	      	{
		    if(ptr!=null)
		    {
		        s.push(ptr);
		        s1.push('l');
		        ptr=ptr.lc;
		
		    }
		    else
		    {
		        ptr=s.pop();
		        flag=s1.pop();
		        if(flag=='l')
		        {
		            s.push(ptr);
		            s1.push('r');
		            ptr=ptr.rc;
		           
		        }
		        else
		        {
		            System.out.println(ptr.data);
		            ptr=null;
		        }
		    }
		}  
	      
    }




}


public class Mytree {

	public static void main(String[] args) 
	{
		int ch;
		Scanner sc=new Scanner(System.in);
		
		tree t1= new tree();
		
		t1.create();
		
		while(true)
		{
		
			System.out.println("\n----------MENU----------");
			System.out.println("1.Recursive inorder");
			System.out.println("2.Recursive preorder");
			System.out.println("3.Recursive postorder");
			System.out.println("4.Non-recursive inorder");
			System.out.println("5.Non-recursive preorder");
			System.out.println("6.Non-recursive postorder");
			System.out.println("------------------------\n");

			System.out.println("Enter your choice");
			ch=sc.nextInt();
			System.out.println("------------------------\n");


			switch(ch)
			{
				case 1:
						t1.r_inorder();
						break;
						
				case 2:
						t1.r_preorder();
						break;
				
				case 3:
						t1.r_postorder();
						break;
					
				case 4:
						t1.nr_inorder();
						break;
						
				case 5:
						t1.nr_preorder();
						break;
						
				case 6:
						t1.nr_postorder();
						break;
				
				default:
						System.out.println("Invalid choice!");
						break;
				
			}	
		}
		
		
	}

}

/*

OUTPUT:

Enter the node:
1
Node inserted!


Do you want to continue creating? (Y/N)
y
Enter the node:
2

1
Enter the direction: (L/R)
l
Node inserted!


Do you want to continue creating? (Y/N)
y
Enter the node:
3

1
Enter the direction: (L/R)
r
Node inserted!


Do you want to continue creating? (Y/N)
y
Enter the node:
4

1
Enter the direction: (L/R)
l

2
Enter the direction: (L/R)
r
Node inserted!


Do you want to continue creating? (Y/N)
y
Enter the node:
5

1
Enter the direction: (L/R)
r

3
Enter the direction: (L/R)
l
Node inserted!


Do you want to continue creating? (Y/N)
n

----------MENU----------
1.Recursive inorder
2.Recursive preorder
3.Recursive postorder
4.Non-recursive inorder
5.Non-recursive preorder
6.Non-recursive postorder
------------------------

Enter your choice
1
------------------------

2
4
1
5
3

----------MENU----------
1.Recursive inorder
2.Recursive preorder
3.Recursive postorder
4.Non-recursive inorder
5.Non-recursive preorder
6.Non-recursive postorder
------------------------

Enter your choice
4
------------------------

2
4
1
5
3

----------MENU----------
1.Recursive inorder
2.Recursive preorder
3.Recursive postorder
4.Non-recursive inorder
5.Non-recursive preorder
6.Non-recursive postorder
------------------------

Enter your choice
2
------------------------

1
2
4
3
5

----------MENU----------
1.Recursive inorder
2.Recursive preorder
3.Recursive postorder
4.Non-recursive inorder
5.Non-recursive preorder
6.Non-recursive postorder
------------------------

Enter your choice
5
------------------------

1
2
4
3
5

----------MENU----------
1.Recursive inorder
2.Recursive preorder
3.Recursive postorder
4.Non-recursive inorder
5.Non-recursive preorder
6.Non-recursive postorder
------------------------

Enter your choice
3
------------------------

4
2
5
3
1

----------MENU----------
1.Recursive inorder
2.Recursive preorder
3.Recursive postorder
4.Non-recursive inorder
5.Non-recursive preorder
6.Non-recursive postorder
------------------------

Enter your choice
6
------------------------

4
2
5
3
1

*/
