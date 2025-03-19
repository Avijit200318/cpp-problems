// gfg -> N-Queen Problem

// Input: n = 4
// Output: [[2 4 1 3 ] [3 1 4 2 ]]
// Explaination: There are 2 possible solutions for n = 4.


//{ Driver Code Starts
// Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

void addElements(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    vector<int> temp;
    for(int i = 0; i< n; i++){
        for(int j = 0; j< n; j++){
            if(board[i][j] == 1){
                temp.push_back(j+1);
            }
        }
    }
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    int x = row, y = col;

    // check <--- this side of the board
    while(y >= 0){
        if(board[x][y] == 1) return false;
        y--;
    }

    // check left-top <-- side of the board
    x = row;
    y = col;

    while(x >= 0 && y >= 0){
        if(board[x][y] == 1) return false;
        x--;
        y--;
    }

    x = row;
    y = col;

    while(x < n && y >= 0){
        if(board[x][y] == 1) return false;
        x++;
        y--;
    }

    return true;
}

void solve(int col, int n, vector<vector<int>> &ans, vector<vector<int>> &board){
    if(col == n){
        // ans.push_back(board);
        addElements(ans, board, n);
        return;
    }

    for(int row = 0; row< n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 1;
            solve(col+1, n, ans, board);

            board[row][col] = 0;
        }
    }
}

vector<vector<int>> NqueensProblem(int n){
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(0, n, ans, board);
    return ans;
}

int main(){
    vector<vector<int>> a = NqueensProblem(4);
    for(int i = 0; i< a.size(); i++){
        for(int j = 0; j< a[i].size(); j++){
            cout<< a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
