#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void printMatrix(int** matrix, int nV) {
    cout<<endl<<"Output Matrix (containing shortest paths) :"<<endl ;
    for (int i=0; i<nV; i++) {
        for (int j=0; j<nV; j++) {
            if (matrix[i][j] == 999)
                cout<<"INF"<<"\t" ;
            else
                cout<<matrix[i][j]<<"\t" ;
        }
    cout<<endl ;
  }
}

void floydWarshall(int** graph, int nV) {
  int** matrix = new int*[nV] ;
  for(int i=0;i<nV;i++) {
    matrix[i] = new int[nV] ;
  }

  for (int i=0; i<nV; i++)
    for (int j=0; j<nV; j++)
      matrix[i][j] = graph[i][j];

  for (int k=0; k<nV; k++) {
    for (int i=0; i<nV; i++) {
      for (int j=0; j<nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix, nV);
}

int main() {

    int nV ;

    cout<<"Enter no. of vertices : " ;
    cin>>nV ;

    int **graph = new int*[nV] ;
    for(int i=0;i<nV;i++) {
        graph[i] = new int[nV] ;
    }

    cout<<endl<<"Enter Graph Values : "<<endl ;
    cout<<"Note: Enter -1 for infinite value."<<endl<<endl ;

    for(int i=0;i<nV;i++) {
        for(int j=0;j<nV;j++) {
            int x ;
            cout<<"Enter Graph["<<i<<"]["<<j<<"] : " ;
            cin>>x ;

            if(x == -1)
                graph[i][j] = 999 ;
            else
                graph[i][j] = x ;
        }
    }
    floydWarshall(graph, nV);
}
