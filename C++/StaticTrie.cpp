// Statica Trie implementation to the question "UVA crazy search"
// AbraaoCF
#include<bits/stdc++.h>
using namespace std;

int trie[16000001][26], finish[16000001];
int nxt = 1;
int cnt = 0;
void add (string s){
    int node = 0;

    for (int i = 0; s[i] != '\0'; i++) 
    {
        if(trie[node][s[i] - 'a'] == 0)
        {
            node = trie[node][s[i] - 'a'] = nxt;
            nxt++;
        }
        else 
            node = trie[node][s[i] - 'a'];
    }
    if(!finish[node]) cnt++;
    finish[nxt - 1] = 1;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        for(int i = 0; i <= nxt+1; i++)
        {
            for(int j = 0; j < 26; j++)
                trie[i][j] = 0;
            
            finish[i] = 0;
        }
        nxt = 1;
        for(int i = 0; i < (int)s.size()-n+1; i++)
            add(s.substr(i,n));
        
        cout << cnt << "\n"; 
        cnt = 0;
        if(t > 0) cout << "\n";
    }
    return 0;
}
