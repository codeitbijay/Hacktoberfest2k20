#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2)  
{  
    int L[s1.size() + 1][s2.size() + 1];  
    int i,j;  
      
    for (i=0;i<=s1.size();i++)  
    {  
        for (j=0;j<=s2.size();j++)  
        {  
            if (i==0 || j==0)
            {
                L[i][j]=0;
            }    
            else if (s1[i - 1] == s2[j - 1])
            {
                L[i][j]=L[i-1][j-1]+1;
            }    
            else
            {
                L[i][j]=max(L[i-1][j],L[i][j-1]);
            }  
        }  
    }  
    return L[s1.size()][s2.size()];  
}  

int main()
{
    string s1,s2;
    cout<<"LOngEst CommOn SuBSeqUencE" << endl;
    cout << "Enter 1st String" << endl;
    cin>>s1;
    cout << "Enter 2nd String" << endl;
    cin>>s2;
    cout<<lcs(s1,s2)<<endl;    
}