template <typename V>
class MapNode{
	public:
		MapNode* next;//template name kyun nahi specify kiya yahan?
		V data;
		string key;
		MapNode(string key,V value){
			this->key=key;
			this->value=value;
			next=NULL;
		}
		~MapNode(){
			delete next;
		}
	
};
template <typename V>
class map{
	public:
		int count=0;
		int bucketSize=5;
		MapNode<V>** buckets;
		map(string key,V value){
			this->count=0;this->bucketSize=5;
			buckets=new MapNode<V>*[bucketSize];
			for(int i=0;i<bucketSize;i++){
				buckets[i]=NULL;
			}
		}
		~map(){
			for(int i=0;i<bucketSize;i++){
				MapNode* temp=buckets[i];//yahan doubt hai
				delete temp;
			}
			delete [] buckets;
		}
	private:
		int hashCodeGenerator(string key){
			int p=31,multiplier=1;//primes have been proven to be the best base for hashmaps
			int hashcode=0;
			for(int i=key.size()-1;i>=0;i--){
				int ch='0'+key[i];
				hashcode+=(ch*multiplier);
				hashcode=hashcode%bucketSize;
				multiplier*=p;
				multiplier=multiplier%bucketSize;
			}
			return hashcode % bucketSize;
		}
	private:
		void rehash(){
			MapNode<V>** temp=buckets;
			buckets=new MapNode<V>*[2*bucketSize];
			int oldBucketSize=bucketSize;
			this->count=0;
			this->bucketSize*=2;
			for(int i=0;i<bucketSize;i++){
				buckets[i]=NULL;
			}
			for(int i=0;<oldBucketSize;i++){
				MapNode<V>* head=temp[i];
				while(head!=NULL){
					insert(head->key,head->value);
					head=head->next;
				}
			}
			for(int i=0;i<oldBucketSize;i++){
				delete temp[i];
			}
			delete [] temp;
		}
	public:
		int size(){
			return count;
		}
		V getValue(string key){
			int bucketIndex=hashCodeGenerator(key);
			MapNode<V>* head=buckets[bucketIndex];
			while(head!=NULL){
				if(head->key==key){return head->value;}
				head=head->next;
			}
			return 0;
		}
		void insert(string key,V value){
			int bucketIndex=hashCodeGenerator(key);
			MapNode<V>* head=buckets[bucketIndex];
			while(head!=NULL){
				if(head->key==key){head->value=value;return;}
				head=head->next;
			}
			MapNode<V>* temp=new MapNode<V>(key,value);
			temp->next=buckets[bucketIndex];
			buckets[bucketIndex]=temp;
			count+=1;
			double loadFactor=(1.0*count)/(bucketSize*1.0);
			if(loadFactor>0.7){rehash();}
			return;
		}	
		V deleteKey(string key){
			V val;
			int bucketIndex=hashCodeGenerator(key);
			MapNode<V>* head=buckets[bucketIndex];
			MapNode<V>* prev=NULL;
			while(head!=NULL){
				if(head->key==key){
					if(prev==NULL){
						MapNode<V>* temp=buckets[bucketIndex]->next;
						buckets[bucketIndex]->next=NULL;
						val=buckets[bucketIndex]->value;
						delete buckets[bucketIndex];
						buckets[bucketIndex]=temp;
						return val;
					}
					else{
						prev->next=head->next;
						head->next=NULL;
						val=head->value;
						delete head;
						return val;
					}
					count-=1;
				}
				prev=head;
				head=head->next;
			}
			return 0;
		}	
};