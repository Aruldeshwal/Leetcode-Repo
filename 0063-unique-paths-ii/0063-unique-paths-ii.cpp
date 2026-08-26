class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long long>> dp(n + 1, vector<long long> (m + 1, 0));
        if(obstacleGrid[n - 1][m - 1] != 1) {
            dp[n - 1][m - 1] = 1;
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1) continue;
                
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                long long rightWay = dp[i][j + 1];
                long long downWay = dp[i + 1][j];
                dp[i][j] = rightWay + downWay;
            }
        }

        return dp[0][0];
    }
};