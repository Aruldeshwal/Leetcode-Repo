class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(dp[i + 1][j] != -1 && dp[i][j + 1] != -1) {
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                } 
                else if(dp[i + 1][j] == -1 && dp[i][j + 1] != -1) {
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                }
                else if(dp[i + 1][j] != -1 && dp[i][j + 1] == -1) {
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                }
                else dp[i][j] = grid[i][j];
                
            }
        }
        return dp[0][0];
    }
};