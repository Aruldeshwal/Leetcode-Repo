class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0; // Stores dp[i + 2]
        int prev1 = 0; // Stores dp[i + 1]

        // Iterate from the last house to the first
        for (int index = n - 1; index >= 0; index--) {
            int include = nums[index] + prev2; // Rob current house, skip next
            int exclude = prev1;               // Skip current house

            // Shift window: update prev2 and prev1 for next iteration
            prev2 = prev1;
            prev1 = max(include, exclude); // Choose better of robbing or skipping
        }

        return prev1; // Final answer: max money robbable from house 0
    }
};
