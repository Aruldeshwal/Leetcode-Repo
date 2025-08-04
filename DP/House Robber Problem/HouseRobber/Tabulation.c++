class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Create a dp array with 2 extra spaces to avoid out-of-bound access
        vector<int> dp(n + 2, 0);

        // Fill dp[] from the back
        for (int index = n - 1; index >= 0; index--) {
            int include = nums[index] + dp[index + 2]; // Rob current house
            int exclude = dp[index + 1];               // Skip current house
            dp[index] = max(include, exclude);         // Take max of both options
        }

        return dp[0]; // Max money robbable from house 0 onward
    }
};
