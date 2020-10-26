//gauravsingh :( 16.10.2020
#include <bits/stdc++.h>
using namespace std;
 
//using int = long long int;
using ll = long long int;
using pii = pair < int, int >;

#define ff first
#define ss second
#define endl '\n'
#define pb push_back

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define rep(i, j, n)	for(int i = j; i < n; i++)
#define ren(i, j, n)	for(int i = n-1; i >= j; i--)

#define cerr cout
void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {
    cerr << t; if(sizeof...(v)) cerr << ", "; _print(v...);
}
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

void io_set(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

//check - if t has exactly three distinct positive divisors.

// 1 - 1 bad
// 2 - 1 2 bad
// 3 - 1 3 bad
// 4 - 1 2 4 good
// 5 - 1 5 bad
// 6 - 1 2 3 6 bad
// 9 - 1 3 9 good
// 16 - 1 2 4 8 16 - bad
// 25 - 1 5 25 good
// 49 - 1 7 49 good
//prime^2 good

const int mod = 1000000007;

const int N = 1000005;

int p[N];


void pre(){
    p[0] = true, p[1] = true;
    for(int i = 2; i * i <= N; i++){
        if(!p[i]){
            for(int j = i*i; j < N; j += i){
                p[j] = true;
            }
        }
    }
}

void solve(){
    long long int n;
    cin >> n;
    long double root = sqrtl(n);
    int val = root;
    bool flag = (root == val && !p[val]);
    cout << (flag ? "YES" : "NO") << endl;
}

signed main(int argc, char **argv){
    io_set();
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int tt = 1;
    pre();
    cin >> tt;
    while(tt--){
        solve();
    }
    return 0;
}


