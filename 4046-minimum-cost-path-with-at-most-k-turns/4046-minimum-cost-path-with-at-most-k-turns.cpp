class Solution {
public:
    
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<vector<vector<int>>>> dist(
            n, vector<vector<vector<int>>>(
                m, vector<vector<int>>(
                    k + 1, vector<int>(5, INT_MAX))));

        // Min-heap tuple: {cost, r, c, rem_k, last_dir}
        using State = tuple<int, int, int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[0][0][k][4] = grid[0][0];
        pq.push({grid[0][0], 0, 0, k, 4});
        while (!pq.empty()) {
            auto [cost, r, c, rem_k, last_dir] = pq.top();
            pq.pop();

            if (r == n - 1 && c == m - 1) return cost;
            if (cost > dist[r][c][rem_k][last_dir]) continue;

            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d].first;
                int nc = c + dirs[d].second;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

                int next_k = rem_k;
                if (last_dir != 4 && last_dir != d) {
                    next_k--;
                }

                if (next_k >= 0) {
                    int next_cost = cost + grid[nr][nc];
                    if (next_cost < dist[nr][nc][next_k][d]) {
                        dist[nr][nc][next_k][d] = next_cost;
                        pq.push({next_cost, nr, nc, next_k, d});
                    }
                }
            }
        }

        return -1;
    }
};