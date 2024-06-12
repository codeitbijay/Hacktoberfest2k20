#include <iostream>
#include <bits/stdc++.h>
using namespace std ;

int minDistance(int dist[], int V, bool sptSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[], int V)
{
	cout<<"Vertex \t\t Distance from Source\n";
	for (int i = 0; i < V; i++)
		cout<<i<<" \t\t "<<dist[i]<<endl;
}

void dijkstra(int** graph,int V, int src)
{
	int dist[V];
    bool sptSet[V];

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, V, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printSolution(dist, V);
}

int main()
{

	int V;
	cout<<"Enter no. of vertices : " ;
	cin>>V ;

	int** graph = new int*[V] ;
    for(int i=0;i<V;i++) {
        graph[i] = new int[V] ;
    }

	for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            graph[i][j] = -1;
        }
	}

	for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            if(graph[i][j] < 0) {
                int temp ;
                cout<<"Enter weight of edge joining vertex "<<i<<" & "<<j<<" : " ;
                cin>>temp ;

                graph[i][j] = temp ;
                graph[j][i] = temp ;
            }
        }
	}
    cout<<endl ;
	dijkstra(graph, V, 0);

	return 0;
}
