#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cout<<"\n Enter the number of processes : ";
    cin>>n;
    cout<<"\n Enter maximum number of resources type : ";
    cin>>m;
    int available[m];
    bool finish[n]={};
    int max[n][m],allocation[n][m],need[n][m];
    cout<<"\n Enter Maximum demand of each process of each type ...\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>max[i][j];
        }
    }
    cout<<"\n Enter Already Allocated resources to each process ...\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>allocation[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }
    cout<<"\n Enter available resource of each type of resource ...\n";
    for(int i=0;i<m;i++)
    {
        cin>>available[i];
    }
    int y = 0,ind=0,ans[n]; 
    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            if (finish[i] == 0) { 
  
                int flag = 0; 
                for (int j = 0; j < m; j++) { 
                    if (need[i][j] > available[j]){ 
                        flag = 1; 
                         break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        available[y] += allocation[i][y]; 
                    finish[i] = 1; 
                } 
            } 
        } 
    }
    for(int i=0;i<n;i++)
    {
        cout<<finish[i]<<"\t";
    }
    for(int i=0;i<n;i++)
    {
        if(finish[i]!=true)
        {
            cout<<"\n Deadlock Detected ...\n";
            exit(0);
        }
    }
    cout<<"\n No deadlock detected ";
    return 0;
}