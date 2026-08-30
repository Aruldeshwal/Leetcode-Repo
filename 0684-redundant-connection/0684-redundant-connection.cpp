class Solution {
public:
    unordered_set<int> cycle;   
    int cycleStart = -1;     
    void dfs(vector<vector<int>>& graph, vector<bool>& vis, int cur, int par = -1) {
        if(vis[cur]) { 
            cycleStart = cur; 
            return; 
        }         
        vis[cur] = true;                                        
        for(auto child : graph[cur]) {                         
            if(child == par) continue;                          
            if(cycle.empty()) dfs(graph, vis, child, cur);     
            if(cycleStart != -1) cycle.insert(cur);             
            if(cur == cycleStart) { 
                cycleStart = -1; 
                return; 
            } 
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = size(edges);
	    vector<vector<int>> graph(n+1);
	    vector<bool> vis(n+1);                
	    for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        dfs(graph, vis, 1);   
	    
        for(int i = n - 1; i >= 0; i--)
		    if(cycle.count(edges[i][0]) && cycle.count(edges[i][1])) return edges[i];  
	    return { };  
    }
};