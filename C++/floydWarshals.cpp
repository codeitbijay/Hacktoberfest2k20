#include <iostream>
using namespace std;

#define V 4
#define INF 999

void printMatrix(int matrix[][V]) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (matrix[i][j] == INF)
        cout<< "INF"<<"\t";
      else
        cout<< matrix[i][j]<< "\t";
    }
    cout<<"\n";
  }
}
void floydWarshall(int matrix[][V]) {
  int  i, j, k;
  for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}
int main() {
  int matrix[V][V] ;
  int i, j; 
  cout<< "Enter the elements in the array, enter 999 for infinite value"<<endl;
  for(i=0; i < V; i++){
      for(j=0; j < V ; j++){
        cin>> matrix[i][j];
        if(matrix[i][j] == 999){
          matrix[i][j] = INF;
        }
      }
  }
  floydWarshall(matrix);
}