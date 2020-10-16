#include<bits/stdc++.h> 
using namespace std; 
#define N 3 
  
//  Function for finding maximum sum 
int maxPathSum(int tri[][N], int m, int n) 
{ 
     // loop for bottom-up calculation 
     for (int i=m-1; i>=0; i--) 
     { 
        for (int j=0; j<=i; j++) 
        { 
            // for each element, check both 
            // elements just below the number 
            // and below right to the number 
            // add the maximum of them to it 
            if (tri[i+1][j] > tri[i+1][j+1]) 
                tri[i][j] += tri[i+1][j]; 
            else
                tri[i][j] += tri[i+1][j+1]; 
        } 
     } 
  
     // return the top element 
     // which stores the maximum sum 
     return tri[0][0]; 
} int main() 
{ 
   int N;
   cin>>N;
	 int tri[N][N];
	 for(int i=0;i<N;i++)
	 {
	    for(int j=0;j<N;j++)
			  cin>>tri[i][j];
	 }
	 
   cout << maxPathSum(tri, N, N); 
   return 0; 
} 
