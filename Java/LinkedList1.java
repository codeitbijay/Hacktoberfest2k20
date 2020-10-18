

public class LinkedList1<T> {


	private class Node{
		T data;
		Node next;
	}
	private Node head;
	private Node tail;
	private int size;
	public void display() {
		Node temp = this.head;
		while(temp!=null) {
			System.out.print(temp.data+" ");
			temp=temp.next;
		}
		System.out.println();
	}
	public void AddLast(T x) {
		Node n1 = new Node();
		n1.data=x;
		n1.next=null;
		if(this.size>=1) {
			this.tail.next=n1;
		}
		if(this.size==0) {
			this.head = n1;
			this.tail = n1;
			this.size++;
		}else {
			this.tail = n1;
			this.size++;
		}
	}
	public void AddFirst(T x) {
		Node n1 = new Node();
		n1.data=x;
		n1.next=null;
		if(this.size==0) {
			this.head = n1;
			this.tail = n1;
			this.size++;
		}
		else {
			n1.next = this.head;
			this.head = n1;
		}
	}
	private Node GetNodeAt(int index) throws Exception {
		if(this.size==0) {
			throw new Exception("LinkedList is null");	
		}
		if(index<0 || index>=this.size) {
			throw new Exception("Index is Wrong");
		}
		Node temp = this.head;
		for(int i =1;i<=index;i++) {
			temp=temp.next;
		}
		return temp;
	}
	public T GetFirst() throws Exception {
		if(this.size==0) {
			throw new Exception("Size of LL is Zero");
		}
		return this.head.data;
	}
	public T GetLast() throws Exception {
		if(this.size==0) {
			throw new Exception("Size of LL is Zero");
		}
		return this.tail.data;
	}
	public T RemoveFirst() throws Exception {
		if(this.size==0) {
			throw new Exception("LL is Empty");
		}
		T rv = this.head.data;
		if(this.size==1) {
			this.head = null;
			this.tail=null;
			this.size=0;
		}else {
		
		this.head = this.head.next;
		this.size--;
		}
		return rv;
	}
	public T RemoveLast() throws Exception {
		if(this.size==0) {
			throw new Exception("LL is Empty");
		}
		T rv = this.tail.data;
		if(this.size==0) {
			this.head = null;
			this.tail = null;
			this.size=0;
		}
		else {
			Node temp = this.head;
			while(temp.next.next!=null) {
				temp= temp.next;
			}
			this.tail = temp;
			this.tail.next=null;
		}
		return rv;
	}
	public T RemoveAt(int index) throws Exception {
		if(this.size==0) {
			throw new Exception("LL is Empty");
		}
		if(index<0||index>this.size) {
			throw new Exception("Wrong index given");
		}
		if(index==0) {
			return RemoveFirst();
		}
		else if(index==this.size-1) {
			return RemoveLast();
		}else {
			Node n1 = GetNodeAt(index-1);
			 Node n2 = n1.next;
			 n1.next = n2.next;
			 this.size--;
			 return n2.data;
			
		}
	
	
	
	}
	public void Reverse() throws Exception {
		int left =0;
		int right = this.size-1;
		while(left<right) {
			Node left1 = GetNodeAt(left);
			Node right1 = GetNodeAt(right);
			T temp = left1.data;
			left1.data= right1.data;
			right1.data =temp;
			left++;
			right--;
		}
	}

}


