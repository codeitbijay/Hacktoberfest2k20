// C++ program to print top 
// view of binary tree 

#include <bits/stdc++.h> 
using namespace std; 

// Structure of binary tree 
struct Node 
{ 
	Node * left; 
	Node* right; 
	int hd; 
	int data; 
}; 

// function to create a new node 
Node* newNode(int key) 
{ 
	Node* node=new Node(); 
	node->left = node->right = NULL; 
	node->data=key; 
	return node; 
} 

// function should print the topView of 
// the binary tree 
void topview(Node* root) 
{ 
	if(root==NULL) 
	return; 
	queue<Node*>q; 
	map<int,int> m; 
	int hd=0; 
	root->hd=hd; 
	
	// push node and horizontal distance to queue 
	q.push(root); 
	
	cout<< "The top view of the tree is : \n"; 
	
	while(q.size()) 
	{ 
		hd=root->hd; 
		
		// count function returns 1 if the container 
		// contains an element whose key is equivalent 
		// to hd, or returns zero otherwise. 
		if(m.count(hd)==0) 
		m[hd]=root->data; 
		if(root->left) 
		{ 
			root->left->hd=hd-1; 
			q.push(root->left); 
		} 
		if(root->right) 
		{ 
			root->right->hd=hd+1; 
			q.push(root->right); 
		} 
		q.pop(); 
		root=q.front(); 
		
	} 
	
	
	
	for(auto i=m.begin();i!=m.end();i++) 
	{ 
		cout<<i->second<<" "; 
	} 
	
} 

// Driver Program to test above functions 
int main() 
{ 
	/* Create following Binary Tree 
			1 
		/ \ 
		2 3 
		\ 
			4 
			\ 
			5 
			\ 
				6*/
Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->right = newNode(4); 
	root->left->right->right = newNode(5); 
	root->left->right->right->right = newNode(6); 
	cout<<"Following are nodes in top view of Binary Tree\n"; 
	topview(root); 
	return 0; 
} 
/* This code is contributed by Niteesh Kumar */

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); // Add w to v’s list. 
} 

void Graph::DFSUtil(int v, bool visited[]) 
{ 
	// Mark the current node as visited and 
	// print it 
	visited[v] = true; 
	cout << v << " "; 

	// Recur for all the vertices adjacent 
	// to this vertex 
	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited); 
} 

// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSUtil(v, visited); 
} 

// Driver code 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(4); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3); 

	cout << "Following is Depth First Traversal"
			" (starting from vertex 2) \n"; 
	g.DFS(2); 

	return 0; 
} 
