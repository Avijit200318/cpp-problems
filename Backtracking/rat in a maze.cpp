#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> visit, vector<vector<int>> arr){
    if((x >= 0 && x < n) && (y >= 0 && y < n) && visit[x][y] != 1 && arr[x][y] == 1){
        return true;
    }
    return false;
}

void solve(vector<vector<int>> &arr, int x, int y, int n, vector<vector<int>> &visit, vector<string> &ans, string path){
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }

    if(arr[0][0] == 0) return;

    // down left right up
    if(isSafe(x+1, y, n, visit, arr)){
        visit[x][y] = 1;
        solve(arr, x+1, y, n, visit, ans, path + 'D');
        visit[x][y] = 0;
    }

    if(isSafe(x, y-1, n, visit, arr)){
        visit[x][y] = 1;
        solve(arr, x, y-1,n, visit, ans, path + 'L');
        visit[x][y] = 0;
    }

    if(isSafe(x, y+1, n, visit, arr)){
        visit[x][y] = 1;
        solve(arr, x, y+1, n, visit, ans, path + 'R');
        visit[x][y] = 0;
    }

    if(isSafe(x-1, y, n, visit, arr)){
        visit[x][y] = 1;
        solve(arr, x-1, y, n, visit, ans, path + 'U');
        visit[x][y] = 0;
    }
}

int main(){
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    int n = arr.size();

    vector<vector<int>> visit(n ,vector<int>(n, 0));
    vector<string> ans;
    string path = "";

    solve(arr, 0, 0, n, visit, ans, path);

    for(int i = 0; i< ans.size(); i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}
