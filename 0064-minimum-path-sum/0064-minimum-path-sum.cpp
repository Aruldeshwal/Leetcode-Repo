class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> currRow(m + 1, -1);
        vector<int> nextRow(m + 1, -1);
        
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(nextRow[j] != -1 && currRow[j + 1] != -1) {
                    currRow[j] = grid[i][j] + min(nextRow[j], currRow[j + 1]);
                } 
                else if(nextRow[j] == -1 && currRow[j + 1] != -1) {
                    currRow[j] = grid[i][j] + currRow[j + 1];
                }
                else if(nextRow[j] != -1 && currRow[j + 1] == -1) {
                    currRow[j] = grid[i][j] + nextRow[j];
                }
                else currRow[j] = grid[i][j];
                
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }
};