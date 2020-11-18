#include<bits/stdc++.h>
using namespace std;

#define NIL 0

int FULL;
vector<map<int,int>> rowsMap(9);
vector<map<int,int>> colsMap(9);
vector<map<int,int>> internalMap(9);
vector<vector<int>> board(9, vector<int>(9, 0));
vector<vector<int>> empty;
void getEmptyPositions(vector<vector<int>>);
void initialiseMaps(vector<vector<int>>);
bool isBoardValid();
bool isMoveValid();
void assignToMaps(int, int, int);
void removeFromMaps(int, int, int);
void solve();

void assignToMaps(int row, int col, int val){
    int pos = (row/3)*3+col/3;
    rowsMap[row][val]++;
    colsMap[col][val]++;
    internalMap[pos][val]++;
}

void removeFromMaps(int row, int col, int val){
    int pos = (row/3)*3+col/3;
    rowsMap[row][val]--;
    colsMap[col][val]--;
    internalMap[pos][val]--;
}

bool isBoardValid(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            int val = board[i][j]-1;
            if(val > 0){
                int pos = (i/3)*3+j/3;
                if(rowsMap[i][val] > 1 || colsMap[j][val] > 1 || internalMap[pos][val] > 1) return false;
            }
        }
    }
    return true;
}

bool isMoveValid(int row, int col, int val){
    int pos = (row/3)*3+col/3;
    if(rowsMap[row][val] > 1 || colsMap[col][val] > 1 || internalMap[pos][val] > 1) return false;
    return true;
}

void getEmptyPositions(vector<vector<int>> start){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(start[i][j] == NIL) empty.push_back({i, j});
        }
    }
}

void initialiseMaps(vector<vector<int>> board){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] != NIL){
                assignToMaps(i, j, board[i][j]-1);
            }
        }
    }
}

bool solve(int pos){
    if(pos < 0) return false;
    if(pos == FULL) return true;
    int row = empty[pos][0], col = empty[pos][1];
    for(int i = 1; i <= 9; i++){
        board[row][col] = i;
        assignToMaps(row, col, i-1);
        if(isMoveValid(row, col, i-1)){
            if(solve(pos+1)) return true;
            else{
                board[row][col] = NIL;
                removeFromMaps(row, col, i-1);
            }
        }
        else{
            board[row][col] = NIL;
            removeFromMaps(row, col, i-1);
        }
    }
    return false;
}

bool printFormatted(){
    cout<<"{";
    for(int i = 0; i < 9; i++){
        cout<<"{";
        for(int j = 0; j < 9; j++){
            if(j == 8) cout<<"'"<<board[i][j]<<"'";
            else cout<<"'"<<board[i][j]<<"', ";
        }
        if(i < 8)
            cout<<"},\n";
        else cout<<"}";
    }
    cout<<"};\n";
}

int main(){ 
    vector<vector<int> > startConfig = {{0, 6, 7, 0, 0, 0, 0, 9, 0},  
                                        {9, 0, 0, 5, 0, 0, 6, 8, 7},  
                                        {0, 0, 0, 0, 6, 7, 0, 0, 0},  
                                        {0, 1, 9, 4, 0, 0, 0, 0, 0},  
                                        {0, 7, 6, 3, 0, 2, 0, 0, 0},  
                                        {0, 0, 0, 0, 0, 6, 4, 7, 0},  
                                        {0, 0, 0, 8, 2, 0, 0, 0, 0},  
                                        {6, 9, 0, 0, 0, 3, 0, 0, 2},  
                                        {7, 4, 0, 6, 0, 0, 3, 5, 0}};  
    board = startConfig;
    getEmptyPositions(board);
    initialiseMaps(board);
    if(!isBoardValid()){
        cout<<"Initial board not correct\n";
        return 0;
    }
    else{
        cout<<"Initial Config                  Final Ans\n";
    }
    FULL = empty.size();
    bool flag = solve(0);
    if(flag){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(startConfig[i][j] == 0) cout<<". ";
                else cout<<startConfig[i][j]<<" ";
            }
            if( i == 4) cout<<"   --->    ";
            else cout<<"           ";
            for(int j = 0; j < 9; j++){
                if(startConfig[i][j] == 0) cout<<board[i][j]<<" ";
                else cout<<board[i][j]<<" ";
            }
            cout<<endl;
        } cout<<endl;
        if(isBoardValid()){
            cout<<"Verified solution\n";
        }
        else{
            cout<<"Not valid\n";
        }
    }
    else{
        cout<<"Not Solvable\n";
    }
}

