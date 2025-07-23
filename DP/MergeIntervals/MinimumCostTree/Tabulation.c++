class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;  // Stores max leaf value in arr[i...j]
        int n = arr.size();

        // Precompute max value for all subarrays [i...j]
        for(int i = 0; i < n; i++) { 
            maxi[{i, i}] = arr[i];  // Single element base case
            for(int j = i + 1; j < n; j++) {
                // Build max range using previous max
                maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
            }
        }

        // dp[i][j] = min cost to build tree from arr[i...j]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill dp table bottom-up
        for(int left = n - 1; left >= 0; left--) {
            for(int right = left + 1; right < n; right++) {
                int ans = INT_MAX;

                // Try all possible partitions between left and right
                for(int i = left; i < right; i++) {
                    // Left subtree = arr[left...i]
                    // Right subtree = arr[i+1...right]
                    int cost = maxi[{left, i}] * maxi[{i + 1, right}]
                             + dp[left][i]
                             + dp[i + 1][right];

                    // Choose the split with the minimum total cost
                    ans = min(ans, cost);
                }

                // Store result for this subarray
                dp[left][right] = ans;
            }
        }

        // Final answer is the min cost to build tree from full array
        return dp[0][n - 1];
    }
};
