// Ninja’s Training

// Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. 
// (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills,
// he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?

// You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.

// For Example
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.

//   Sample Input 1:
// 2
// 3
// 1 2 5 
// 3 1 1
// 3 3 3
// 3
// 10 40 70
// 20 50 80
// 30 60 90
// Sample Output 1:
// 11
// 210

int solve(int day, int last, vector<vector<int>> &arr){
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                maxi = max(maxi, arr[day][task]);
            }
        }
        return maxi;
    }


    int maxi = 0;

    for(int task = 0; task < 3; task++){
        if(task != last){
            int point = arr[day][task] + solve(day-1, task, arr);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solve(n-1, 3, points);
}

// ****memorization method*****
int solve(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &memo){
    if(day == 0){
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task != last){
                maxi = max(maxi, arr[day][task]);
            }
        }
        return maxi;
    }

    if(memo[day][last] != -1) return memo[day][last];

    int maxi = 0;

    for(int task = 0; task < 3; task++){
        if(task != last){
            int point = arr[day][task] + solve(day-1, task, arr, memo);
            maxi = max(maxi, point);
        }
    }
    memo[day][last] = maxi;
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> memo(n, vector<int>(4, -1));
    return solve(n-1, 3, points, memo);
}

// *********tabulation method**********
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4, 0));

  // if the last element is 0th then we need to store max value between 1st and 2nd element
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1] ,points[0][2]));

    for(int day = 1; day< n; day++){
        for(int last = 0; last < 4; last++){
            int maxi = 0;

            for(int i = 0; i< 3; i++){
                if(i != last){
                    int point = points[day][i] + dp[day-1][i];
                    maxi = max(maxi, point);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[n-1][3];
}

// *****more space optimize*******
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1] ,points[0][2]));

    for(int day = 1; day< n; day++){
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++){
            int maxi = 0;

            for(int i = 0; i< 3; i++){
                if(i != last){
                    int point = points[day][i] + prev[i];
                    maxi = max(maxi, point);
                }
            }
            temp[last] = maxi;
        }
        prev = temp;
    }

    return prev[3];
}

