/* 
Problem : Given an sequence of matrices find the most efficient way to multiply these matices together

Input: p[] = {40, 20, 30, 10, 30}   
Output: 26000  
There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
Let the input 4 matrices be A, B, C and D.  The minimum number of 
multiplications are obtained by putting parenthesis in following way
(A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(vector<int>& v, int st, int en) {
	if(st >= en) {
        return 0;
    }
    if(dp[st][en] != -1) return dp[st][en];
    int val = INT_MAX;
    for(int k = st; k < en; k++) {
		val = min(val, solve(v, st, k) + solve(v, k + 1, en) + v[st - 1] * v[k] * v[en]);
	}
	return dp[st][en] = val;
}

void testCase(){
    vector<int> v{40, 20, 30, 10, 30};
	int n = v.size();
    dp.resize(n, vector<int>(n, -1));
    int val = solve(v, 1, n - 1);
    cout << val << endl;
}

int main(){
    int t = 1;
    while(t--){
        testCase();
    }
}
