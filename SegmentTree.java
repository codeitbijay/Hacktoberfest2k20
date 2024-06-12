
public class SegmentTree {
	private class Node{
		int data;
		int startIndx;
		int endIndx;
		Node left;
		Node right;
	}
	Node root;
	public SegmentTree(int[] arr) {
		this.root = ConstructTree(arr,0,arr.length-1);
	}
	private Node ConstructTree(int[] arr, int si, int ei) {
		if(si==ei) {
			Node leafNode = new Node();
			leafNode.data = arr[si];
			leafNode.startIndx = si;
			leafNode.endIndx = ei;
			return leafNode;
		}
		Node node = new Node();
		node.startIndx = si;
		node.endIndx = ei;
		int mid = (si+ei)/2;
		node.left = this.ConstructTree(arr, si, mid);
		node.right = this.ConstructTree(arr, mid+1, ei);
		node.data = node.left.data +node.right.data;
		
		
		return node;
	}
	public void display() {
		this.display(this.root);
	}
	private void display(Node node) {
		String str = "";
		if(node.left!= null) {
			str = str+" Interval = [ " + node.left.startIndx + " - " + node.left.endIndx + " ] and data = " + node.left.data+" => ";
		}
		else {
			str=  str +" NO LEFT CHILD ";
		}
		str = str + " Interval = [ " + node.startIndx + " - " + node .endIndx + " [ and Data = " + node .data;
		if(node.right!= null) {
			str = str = " <= data is = "  + node.right.data + " and Interval is [ " + node.right.startIndx + " - " + node.right.endIndx + "]";
		}
		else {
			str=  str +" <= NO RIGHT CHILD ";
		}
		System.out.println(str);
		if(node.left!= null) {
			this.display(node.left);
		}
		if(node.right!= null) {
			this.display(node.right);
		}
	}
	public int query(int qsi,int qei) {
		return this.query(this.root,qsi, qei);
	}
	private int query(Node node, int qsi, int qei) {
		if(node.startIndx>=qsi && node.endIndx<=qei) {
			return node.data;
		}
		else if(node.startIndx>qei || node.endIndx<qsi){
			return 0;
			
		}
		else {
			int leftans = this.query(node.left, qsi,qei);
			int rightans = this.query(node.right, qsi, qei);
			return leftans+rightans;
		}
		
	}
	public void update(int index,int newValue) {
		this.root.data = this.update(this.root, index,newValue);
	}
	private int update(Node root2, int index, int newValue) {
		
		if(index>=root2.startIndx && index<=root2.endIndx) {
			if(index==root2.startIndx && index==root2.endIndx) {
			root2.data = newValue;
			}
		
		else {
			int leftV = this.update(root2.left, index, newValue);
			int rightV = this.update(root2.right, index, newValue);
			root2.data = leftV+rightV;
					
		}
		}
		return root2.data;
	}

}
