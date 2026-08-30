class Solution {
public:
    void traversal(int i, int j, vector<vector<bool>> &visited, vector<pair<int, int>> &directions, vector<vector<char>> &grid) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1' || visited[i][j]) return;
        visited[i][j] = 1;
        for(auto &it : directions) {
            traversal(i + it.first, j + it.second, visited, directions, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), 0));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    traversal(i, j, visited, directions, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};