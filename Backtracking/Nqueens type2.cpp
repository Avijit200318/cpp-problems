// 51. N-Queens -> leetcode

// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// the output is vector<vector<stirng>> then the bellow process
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above


#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<string> &board, int n){
    int x = row, y = col;

    // check <--- this side of the board
    while(y >= 0){
        if(board[x][y] == 'Q') return false;
        y--;
    }

    // check left-top <-- side of the board
    x = row;
    y = col;

    while(x >= 0 && y >= 0){
        if(board[x][y] == 'Q') return false;
        x--;
        y--;
    }

    x = row;
    y = col;

    while(x < n && y >= 0){
        if(board[x][y] == 'Q') return false;
        x++;
        y--;
    }

    return true;
}

void solve(int col, int n, vector<vector<string>> &ans, vector<string> &board){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row = 0; row< n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(col+1, n, ans, board);

            board[row][col] = '.';
        }
    }
}

vector<vector<string>> NqueensProblem(int n){
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solve(0, n, ans, board);
    return ans;
}

int main(){
    vector<vector<string>> a = NqueensProblem(4);
    for(int i = 0; i< a.size(); i++){
        for(int j = 0; j< a[i].size(); j++){
            for(int k = 0; k< a[i][j].size(); k++){
                cout<<a[i][j][k];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
