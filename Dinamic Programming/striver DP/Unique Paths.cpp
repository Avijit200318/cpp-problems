// ****memorization*******

#include <bits/stdc++.h> 
int solve(int i, int j, vector<vector<int>> &dp){
	if(i == 0 && j == 0) return 1;
	if(i < 0 || j < 0) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int up = solve(i-1, j, dp);
	int left = solve(i, j-1, dp);

	dp[i][j] = up + left;
	return up + left;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	return solve(m-1, n-1, dp);
}

//*****tabulization**********

#include <bits/stdc++.h> 
int solve(int m, int n){
	if(m == 1 && n == 1) return 1;
	if(m == 0 || n == 0) return 0;

	vector<vector<int>> dp (m, vector<int>(n, -1));
	dp[0][0] = 1;

	for(int i = 0; i<m; i++ ){
		for(int j = 0; j< n; j++){
			if(i == 0 && j == 0) continue;
			int up = i-1 >= 0 ? dp[i-1][j] : 0;
			int left = j-1 >= 0? dp[i][j-1] : 0;

			dp[i][j] = left + up;
		}
	}

	return dp[m-1][n-1];
}

int uniquePaths(int m, int n) {
	return solve(m, n);
}

// more optimize

#include <bits/stdc++.h> 
int solve(int m, int n){

	vector<int> prev(n, 0);

	for(int i = 0; i<m; i++ ){
		vector<int> temp(n, 0);
		for(int j = 0; j< n; j++){
			if(i == 0 && j == 0) temp[j] = 1;
			else{
			int up = i-1 >= 0 ? prev[j] : 0;
			int left = j-1 >= 0? temp[j-1] : 0;

			temp[j] = left + up;
			}
		}
		prev = temp;
	}

	return prev[n-1];
}

int uniquePaths(int m, int n) {
	return solve(m, n);
}
