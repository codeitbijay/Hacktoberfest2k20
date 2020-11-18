#include<bits/stdc++.h>
using namespace std;

// debugging : values of variables
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

vector<vector<vector<bool>>> res;
vector<vector<bool>> positions;
unordered_map<int, int> diagonalMap, revDiagonalMap, rowMap;

bool isValid(int row, int col){
    if(rowMap.find(row) != rowMap.end() || diagonalMap.find(row+col) != diagonalMap.end() || revDiagonalMap.find(row-col) != revDiagonalMap.end()){
        return false;
    }
    rowMap[row]++;
    diagonalMap[row+col]++;
    revDiagonalMap[row-col]++;
    positions[row][col] = true;
    return true;
}

void remove(int row, int col){
    rowMap.erase(row);
    diagonalMap.erase(row+col);
    revDiagonalMap.erase(row-col);
    positions[row][col] = false;
}

void solve(int pos, int N){
    if(pos == N) {
		res.push_back(positions);
		return;
	}
    for(int i = 0; i < N; i++){
        if(isValid(i, pos)){
            solve(pos+1, N);
            remove(i, pos);
        }
    }
}

void nqueens(int n){
    positions.resize(n, vector<bool>(n, false));
    solve(0, n);
}

int main(){
    int n, i = 1;
    cin>>n;
    nqueens(n);
	for(auto positions : res) {
		cout << "Config : " << i << endl;
    	for(auto i : positions){
        	for(auto j : i){
            	if(j) cout<<"Q"; else cout<<".";
        	}
        	cout<<endl;
    	}
		cout << "-------------------" << endl;
		i++;
	}
}
