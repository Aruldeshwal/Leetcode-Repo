class Solution {
public:
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        dist[0][0] = 0;
        pq.push({0, 0, 0}); // {effort, r, c}
        
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();
            
            if (effort > dist[r][c]) continue;
            if (r == rows - 1 && c == cols - 1) return effort;
            
            for (auto& d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int nextEffort = max(effort, abs(heights[r][c] - heights[nr][nc]));
                    if (nextEffort < dist[nr][nc]) {
                        dist[nr][nc] = nextEffort;
                        pq.push({nextEffort, nr, nc});
                    }
                }
            }
        }
        return 0;
    }
};