class Solution {
public:
    // Recursive function with memoization to find max money that can be robbed
    int solve(vector<int> &nums, int index, vector<int> &dp) {
        // Base case: if index is beyond the last house, return 0
        if(index >= nums.size()) return 0;

        // Return the cached result if already computed
        if(dp[index] != -1) return dp[index];

        // Option 1: Rob current house and jump to index + 2
        int include = nums[index] + solve(nums, index + 2, dp);

        // Option 2: Skip current house and move to index + 1
        int exclude = solve(nums, index + 1, dp);

        // Store and return the maximum of both options
        return dp[index] = max(include, exclude);
    }

    // Main function to start solving from the 0th index
    int rob(vector<int>& nums) {
        // dp[i] stores the max money that can be robbed from index i onwards
        vector<int> dp(nums.size() + 1, -1);
        return solve(nums, 0, dp);
    }
};
