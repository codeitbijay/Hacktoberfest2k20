#include<bits/stdc++.h>
using namespace std;

class Edge{
	public:
		int src;
		int dest;
		int weight;
};

int getParent(int v,int* parent){
	if(parent[v]==v){
		return v;
	}
	return getParent(parent[v],parent);
}

bool compare(Edge e1,Edge e2){
	return e1.weight < e2.weight;
}

Edge* kruskal(Edge* edges, int n, int E){
	
	sort(edges,edges+E,compare);
	
	Edge* output = new Edge[n-1];
	int* parent = new int[n];
	for(int i=0;i<n;i++)
	parent[i]=i;
	
	int count =0;
	int i=0;
	while(count<(n-1)){
		Edge currentEdge = edges[i];
		int srcParent = getParent(currentEdge.src,parent);
		int destParent = getParent(currentEdge.dest,parent);
		if(srcParent!=destParent){
			output[count] = currentEdge;
			count+=1;
			parent[srcParent] = destParent;
		}
		i++;
	}
	return output;
}

int main(){ 

	int n,E;
	cout<<"Enter no of nodes: ";
	cin>>n;
	cout<<"\nEnter no of edges: ";
	cin>>E;
	Edge* edges = new Edge[E];
	cout<<"\nEnter source,destination and weight of edges\n";
	for(int i=0;i<E;i++){
		int s,d,c;
		cin>>s>>d>>c;
		edges[i].src = s;
		edges[i].dest = d;
		edges[i].weight = c;
	}
	
	Edge* output = kruskal(edges,n,E);
	cout<<"The Edges in MST are:->\n";
	for(int i=0;i<n-1;i++){
		if(output[i].src<output[i].dest){
			cout<<output[i].src<<" -> "<<output[i].dest<<" = "<<output[i].weight<<endl;
		}
		else
			cout<<output[i].dest<<" -> "<<output[i].src<<" = "<<output[i].weight<<endl;
	}
	return 0;
}