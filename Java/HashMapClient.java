
public class HashMapClient {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		 LinkedList<Integer> obj = new LinkedList<>();
		for(int i =0;i<5;i++) {
			obj.AddLast(i);
		}
		System.out.println(obj.RemoveAt(2));
		obj.Reverse();
		obj.display();

	}

}
