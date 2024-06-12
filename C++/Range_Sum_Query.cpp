#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int* tree, int start,int end,int treenode){

    if(start == end){
        tree[treenode] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*treenode);
    buildTree(arr,tree,mid+1,end,2*treenode+1);

    tree[treenode] = tree[2*treenode] +tree[2*treenode+1];
}
int getSumUtil(int *tree, int ss, int se, int qs, int qe, int si)
{
   if (qs <= ss && qe >= se)
        return tree[si];

    if (se < qs || ss > qe)
        return 0;

    int mid = (ss+se)/2;
    return getSumUtil(tree, ss, mid, qs, qe, 2*si) +
        getSumUtil(tree, mid+1, se, qs, qe, 2*si+1);
}
int getSum(int *tree, int n, int qs, int qe)
{
    if (qs < 0 || qe > n || qs > qe)
    {
        cout<<"Invalid Input";
        return -1;
    }

    return getSumUtil(tree, 1, n, qs, qe, 1);
}
int main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    int* tree = new int[4*n];
    buildTree(ar,tree,0,n-1,1);
    int startRange,endRagne;
    cin>>startRange>>endRagne;
    cout<<"Updated sum of values in given range = "
            <<getSum(tree, n, startRange, endRagne)<<endl;
    return 0;
}