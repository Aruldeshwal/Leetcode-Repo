class Solution {
public:
    int solve(vector<int> &nums, int sum, int i, vector<vector<int>> &dp) {
        if(sum == 0) return 0;
        if(i >= nums.size()) return INT_MAX;
        if(sum < 0) return INT_MAX;     
        if(dp[i][sum] != -1) return dp[i][sum];
        int ans = INT_MAX;
        ans = min(ans, solve(nums, sum, i + 1, dp));
        int val = nums[i];
        int opp = 0; 
        while(val){    
            val /= 2; 
            opp++;
            int rr = solve(nums, sum - val, i + 1, dp); 
            if(rr != INT_MAX) rr = rr + opp; 
            ans = min(ans, rr);
        }
        val = nums[i];
        opp = 0; 
        while(val <= 5000){
            int rr = solve(nums, sum - val, i + 1, dp);
            if(rr != INT_MAX) rr = rr + opp;  
            ans = min(ans, rr);
            opp++; 
            val = val * 2; 
        }
        return dp[i][sum] = ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        vector<vector<int>> dp(nums.size() + 1, vector<int> (5002, -1));
        int ans = solve(nums, sum, 0, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};