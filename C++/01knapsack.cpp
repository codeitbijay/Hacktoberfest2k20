// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
//Memoization
int t[100][100];

int knapsack(int wt[],int val[],int w,int n){
    if(n==0||w==0){
        return 0;
    }

    if(t[n][w]!=-1) return t[n][w];

    if(wt[n-1]<=w){
        return t[n][w] =max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),
            knapsack(wt,val,w,n-1)
        );
    }

    else{
            return t[n][w]= knapsack(wt,val,w,n-1);
    }
}

//Tabulation Method
void knapsackTab(int wt[],int val[],int w,int n){
    int arr[n+1][w+1];
    for(int i=0;i<n+1;i++)
        for(int j=0;j<w+1;j++)
            arr[i][j]=0;


    for(int i=1;i<n+1;i++){
        
        // cout<<"For element "<<i<<": "<<endl;
        for(int j=1;j<w+1;j++){
            // cout<<"For weight "<<j<<": "<<endl;
            if(wt[i-1]<=j){
                // cout<<arr[i-1][j-wt[i]]<<" "<<arr[i-1][j]<<" "<<val[i-1]<<endl;
                arr[i][j]=max(val[i-1]+arr[i-1][j-wt[i-1]] , arr[i-1][j]);
            }
            else{
                arr[i][j]=arr[i-1][j];
            }
        }
                cout<<endl;
    }
     cout<<arr[n][w];

}

int main(){
    memset(t,-1,sizeof(t));
    // int wt[]={2,4,1,6,7};
    // int val[]={3,1,7,2,4};

    int n,amount; cin>>n>>amount;

    int *wt=new int [n];
    int *val=new int [n];
    for(int i=0;i<n;i++) cin>>wt[i]>>val[i];


    //INPUT FORMAT
    //n->array size
    //amount-> amount given
    //wt[i] & val [i] -> weight of ith element and its value
    //Sample input -> 5 10 2 3 4 1 1 7 6 2 7 4
    //Output -> 14

    //Using Tabulation
    knapsackTab(wt,val,amount,n);

    cout<<'\n';

    //Using memoization
    cout<<knapsack(wt,val,amount,n);
}