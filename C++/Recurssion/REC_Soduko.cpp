#include<bits/stdc++.h>
using namespace std;
int left(vector<string > &A,int *row,int *col){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(A[i][j]=='.') {
                *row=i;
                *col=j;
                return 1;
            }
        }
    }
    return 0;
}
int correct(vector<string > &A,int i,int j,char num){
        int g=i,h=j;
        for(j=0;j<9;j++){
            if(A[i][j]==num) return 0;
        }
        i=g,j=h;
        for(i=0;i<9;i++){
            if(A[i][j]==num) return 0;
        }
        i=g,j=h;
        int row=i-i%3;
        int col=j-j%3;
        int p,q;
        for(p=0;p<3;p++){
            for(q=0;q<3;q++){
                char cur=A[p+row][q+col];
                if(cur==num) return 0;
            }
        }
        if(A[i][j]=='.')return 1;
        else return 0;
}
int solve(vector<string > &A){
    int i,j;
    if(!left(A,&i,&j)) return 1;
         for(char p='1';p<='9';p++){
            if(correct(A,i,j,p)) {
                    A[i][j]=p;
                if(solve(A)) return 1;
                    A[i][j]='.';
            }
        }
    return 0;
}
int main(){
    vector<string > A = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
    if(solve(A)) {
        for(auto x : A) cout << x <<"\n";
    }
    else cout <<"\n";
}
