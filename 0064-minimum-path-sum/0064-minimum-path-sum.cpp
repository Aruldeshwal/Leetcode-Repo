class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        int n = grid.size(), m = grid[0].size();
        if(i == n || j == m) return dp[i][j] = INT_MAX;
        if(i == n - 1 && j == m - 1) return dp[i][j] = grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(grid, i + 1, j, dp), solve(grid, i, j + 1, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(grid, 0, 0, dp);
    }
};