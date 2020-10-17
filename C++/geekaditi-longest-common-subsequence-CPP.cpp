/* Longest common subsequence in DP using CPP*/

#include <iostream>
#include <vector>
using namespace std;

int LCS(char *a,char *b){
    int n = strlen(a);
    int m = strlen(b);

    int dp[100][100] = {0};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    
    int k = dp[n][m];
    char ans[100];
    ans[k] = '\0';
    k--;
    int i = n;
    int j = m;

    while(k>=0){
        if(a[i-1] == b[j-1]){
            ans[k] = a[i-1];
            k--;i--;j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    cout<<"LCS is "<<ans<<endl;
    return dp[n][m];
}

int main(){

    char a[]="coddingblockss";
    char b[]="codppqwertblocks";

    cout<<LCS(a,b)<<endl;



    return 0;
}
