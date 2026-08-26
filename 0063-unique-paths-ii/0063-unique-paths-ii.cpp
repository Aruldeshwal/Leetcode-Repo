class Solution {
public:
    int solve(vector<vector<int>> &obstacleGrid, int r, int c, vector<vector<int>> &dp) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(r == n || c == m) return dp[r][c] = 0;
        if(obstacleGrid[r][c] == 1) return dp[r][c] = 0;
        if(r == n - 1 && c == m - 1) return dp[r][c] = 1;
        

        if(dp[r][c] != -1) return dp[r][c];
        int rightWay = solve(obstacleGrid, r, c + 1, dp);
        int downWay = solve(obstacleGrid, r + 1, c, dp);
        return dp[r][c] = rightWay + downWay;
    } 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return solve(obstacleGrid, 0, 0, dp);
    }
};