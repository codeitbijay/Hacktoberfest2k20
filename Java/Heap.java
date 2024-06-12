/*

	Title	:	To implement heap data structure.
  
*/

import java.util.Scanner;
    
class heap
{
	int H[];
	Scanner sc=new Scanner(System.in);
	void accept()
	{
		System.out.print("Enter the size of heap: ");
		int n=sc.nextInt();
		
		H=new int[n+5];
		
		H[0]=n;
		System.out.println("Enter elements of heap: ");
		for(int i=1;i<=n;i++)
		{
			H[i]=sc.nextInt();
		}
		
		buildHeap(n);
		display();
		
	}
		
	void buildHeap(int n)
	{
		
		for(int i=n/2;i>=1;i--)
		{
			downAdjust(i,n);
		}
		
	}
	
	void downAdjust(int i,int n)
	{
		int l=2*i;
		int r=(2*i)+1;
		int largest=0;
		
		if(l<=n&&H[l]>H[i])
		{
			largest=l;
		}
		else
		{
			largest=i;
		}
		
		if(r<=n&&H[r]>H[largest])
		{
			largest=r;
		}
		
		if(largest!=i)
		{
			int temp=H[i];
			H[i]=H[largest];
			H[largest]=temp;
			
			downAdjust(largest,n);
		}
				
	}
	
	
	void upAdjust(int i)
	{
		while(i>1)
		{
			int parent=i/2;
			if(H[parent]<H[i])
			{
				int temp=H[i];
				H[i]=H[parent];
				H[parent]=temp;
			}
			i=i/2;
		}
	}
	
	
	void insert()
	{
		System.out.print("Enter the element to be inserted: ");
		int elem=sc.nextInt();
		
		int n=H[0];
		n=n+1;
		H[n]=elem;
		H[0]=n;
		
		
		upAdjust(n);
		
		display();
		
	}
		
	
	void del()
	{
		System.out.print("Enter the element to be deleted: ");
		int elem=sc.nextInt();
		
		int i=1,flag=0;
		int n=H[0];
		
		for(i=1;i<=n;i++)
		{
			if(H[i]==elem)
			{
				flag=1;
				break;
			}
		}
		
		if(flag==1)
		{
			H[i]=H[n];
			H[0]=n-1;
			
			downAdjust(i,H[0]);
			
			display();			
		}
		else
		{
			System.out.println("Element not found!");
		}
	
	}
	
	void sort()
	{
		int first=1;
		int last=H[0];
		
		while(last>0)
		{
			buildHeap(last);
			
			int temp=H[first];
			H[first]=H[last];
			H[last]=temp;
			
			last=last-1;
			
		}
		
		display();
		
	}
	
	void display()
	{
		int n=H[0];
		
		System.out.println();
		for(int i=1;i<=n;i++)
		{
			System.out.print(H[i]+"   ");
		}
		System.out.println();
	}
	
}


class HeapProg
{
	public static void main(String args[])
	{
		heap h=new heap();
		
		Scanner sc=new Scanner(System.in);
		int ch;
		
		do
		{
			System.out.println("\n------MENU------");
			System.out.println("1.Build Heap");
			System.out.println("2.Insert element");
			System.out.println("3.Delete element");
			System.out.println("4.Sort Heap");
			System.out.println("----------------\n");

			System.out.println("Enter your choice");
			ch=sc.nextInt();
			System.out.println("----------------\n");
			
			switch(ch)
			{
				case 1:
						h.accept();						
						break;
						
				case 2:
						h.insert();
						break;
						
				case 3:
						h.del();
						break;
				
				case 4:
						h.sort();
						break;
						
			}
		}while(ch>0&&ch<5);
	}
	
}


/*


OUTPUT:



------MENU------
1.Build Heap
2.Insert element
3.Delete element
4.Sort Heap
----------------

Enter your choice
1
----------------

Enter the size of heap: 14
Enter elements of heap:
10
12
1
14
65
8
15
3
9
7
4
11
13
2

65   14   15   10   12   13   2   3   9   7   4   11   8   1

------MENU------
1.Build Heap
2.Insert element
3.Delete element
4.Sort Heap
----------------

Enter your choice
3
----------------

Enter the element to be deleted: 65

15   14   13   10   12   11   2   3   9   7   4   1   8

------MENU------
1.Build Heap
2.Insert element
3.Delete element
4.Sort Heap
----------------

Enter your choice
3
----------------

Enter the element to be deleted: 1

15   14   13   10   12   11   2   3   9   7   4   8

------MENU------
1.Build Heap
2.Insert element
3.Delete element
4.Sort Heap
----------------

Enter your choice
3
----------------

Enter the element to be deleted: 13

15   14   11   10   12   8   2   3   9   7   4

------MENU------
1.Build Heap
2.Insert element
3.Delete element
4.Sort Heap
----------------

Enter your choice
2
----------------

Enter the element to be inserted: 65

65   14   15   10   12   11   2   3   9   7   4   8

------MENU------
1.Build Heap
2.Insert element
3.Delete element
4.Sort Heap
----------------

Enter your choice
4
----------------


2   3   4   7   8   9   10   11   12   14   15   65



*/
