
public class SegmentTreeClient {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = {3,8,7,6,-2,-8,4,9};
		SegmentTree obj = new SegmentTree(arr);
		obj.display();
		System.out.println(obj.query(3, 3));
		obj.update(3, 14);
		obj.display();
		System.out.println(obj.query(3,3));

	}

}
