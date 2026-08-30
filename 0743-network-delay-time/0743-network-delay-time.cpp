class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            // Optimization: Skip if we already found a faster way to this node
            if (time > dist[node]) continue;
            
            // Explore neighbors
            for(auto& neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int weight = neighbor.second;
                
                // If the new path is faster, update and push to queue
                if(dist[node] + weight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + weight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]); 
        }
        return ans;
    }
};