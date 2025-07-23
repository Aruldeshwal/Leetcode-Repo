class Solution {
public:
    // Recursive function to calculate min cost for arr[left...right]
    int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp){
        // Base case: only one leaf, no internal node to form
        if(left == right) return 0;

        if(dp[left][right] != -1) return dp[left][right];
        
        int ans = INT_MAX;

        // Try all possible partitions between left and right
        for(int i = left; i < right; i++){
            // Cost = max in left subarray * max in right subarray
            // + cost of building left tree + cost of building right tree
            int cost = maxi[{left, i}] * maxi[{i + 1, right}]
                     + solve(arr, maxi, left, i, dp)
                     + solve(arr, maxi, i + 1, right, dp);

            // Take the min across all partitions
            ans = min(ans, cost);
        }

        return dp[left][right] = ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;  // Store max leaf value in arr[i...j]
        int n = arr.size();

        // Precompute max values for all subarrays [i...j]
        for(int i = 0; i < n; i++) { 
            maxi[{i, i}] = arr[i];  // Base case: single element
            for(int j = i + 1; j < n; j++) {
                // max of arr[i...j] = max(arr[i...j-1], arr[j])
                maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
            }
        }

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

        // Start recursive solve from full array
        return solve(arr, maxi, 0, n - 1, dp);
    }
};
