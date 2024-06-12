//connected houses of village 
//here it is understood that connected houses have only 1 number
#include<bits/stdc++.h>
using namespace std;


static int visitMatrix[1000][1000];//size as per constraints

bool inrange(vector<vector<int>>&M,int row,int col,int m,int n)
{
	return((row>=0&&row<m)&&(col>=0&&col<n)&&M[row][col]==1&&visitMatrix[row][col]==0);
}

void DFS(vector<vector<int>>&M,int row,int col,int m,int n,int &size)
{   visitMatrix[row][col]=1;
    size+=1;
	//neighbour matrix
	int nbhr[4][2]={{0,1},{0,-1},{1,0},{-1,0}};//four neighbour of a cell
	for(int k=0;k<4;k++)
	{if(inrange(M,row+nbhr[k][0],col+nbhr[k][1],m,n))
	 DFS(M,row+nbhr[k][0],col+nbhr[k][1],m,n,size);
	}
}
int maxsizeVillage(vector<vector<int>>M,int  m,int n)
{
	int msize[1000]={0};
	int p=0;
	int num=INT_MIN;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(visitMatrix[i][j]==0&&M[i][j]==1)
		   {p++;
			DFS(M,i,j,m,n,msize[p]);
			}
			num=max(num,msize[p]);
		}
	}
	
	return num;
}

int main()
{  
  vector<vector<int>>matrix={{1,0,0,0},
                             {0,1,1,0},
							 {0,0,1,0},
							 {1,0,0,0}};
  memset(visitMatrix,0,matrix.size()*matrix[0].size());
  cout<<maxsizeVillage(matrix,matrix.size(),matrix[0].size());
  return 0;
}
