class Solution {
public:
    int solve(vector<int> &nums, int i, vector<int> &dp) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int include = nums[i] + solve(nums, i + 2, dp);
        int exclude = solve(nums, i + 1, dp);
        return dp[i] = max(include, exclude);
    }
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size() + 1, -1);
        vector<int> dp2(nums.size() + 1, -1);
        return max(solve(nums, 0, dp1), solve(nums, 1, dp2));
    }
};