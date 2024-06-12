import java.util.LinkedList;

public class HashMap {
	public class HashTable<K,V>{
		private class HTpair {
			K key;
			V value;
			HTpair(K key, V value){
				this.key = key;
				this.value = value;
			}
			public boolean equals(Object other) {
				HTpair op = (HTpair)other;
				return this.key.equals(other);
			}
			public String toString() {
				return "{" + this.key +"=>"+this.value+"}";
			}
			
			
		}
		private int size;
		private LinkedList1<HTpair>[] BucketArray ;
		public static final int Default = 10;
		public HashTable() {
			this(Default);
			
		}
		private HashTable(int capacity) {
			this.BucketArray = (LinkedList1<HTpair>[]) new LinkedList1[capacity];
			this.size=0;
		}
		public void put(K key,V value) {
			int bi = hashFunction(key);
			LinkedList1<HTpair>[] bucket = new LinkedList1[bi];
			HTpair pta = new HTpair(key,value);
			if(bucket == null) {
				//bucket = new LinkedList();
			}
			
		}
		private int hashFunction(K key) {
			int hc = key.hashCode();
			hc = Math.abs(hc);
			int bi = hc%this.BucketArray.length;
			return bi;
		}
		
	}

}
