class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<long long> currRow(m + 1, 0);
        vector<long long> nextRow(m + 1, 0);
        if(obstacleGrid[n - 1][m - 1] != 1) {
            currRow[m - 1] = 1;
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(i == n - 1 && j == m - 1) continue;
                
                if(obstacleGrid[i][j] == 1) {
                    currRow[j] = 0;
                    continue;
                }
                long long rightWay = currRow[j + 1];
                long long downWay = nextRow[j];
                currRow[j] = rightWay + downWay;
            }
            nextRow = currRow;
        }

        return nextRow[0];
    }
};