class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (5002, INT_MAX));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= sum; j++) {
                int ans = INT_MAX;
                ans = min(ans, dp[i + 1][j]);
                int val = nums[i];
                int opp = 0; 
                while(val > 0) {    
                    val /= 2; 
                    opp++;
                    if (j >= val) { 
                        int rr = dp[i + 1][j - val]; 
                        if(rr != INT_MAX) rr = rr + opp; 
                        ans = min(ans, rr);
                    }
                }
                val = nums[i];
                opp = 0; 
                while(val <= 5000){
                    if (j >= val) {
                    int rr = dp[i + 1][j - val];
                    if(rr != INT_MAX) rr = rr + opp;  
                    ans = min(ans, rr);
                    } 
                    else {
                        break; 
                    }
                    
                    if (val == 0) break; 
                    
                    opp++; 
                    val = val * 2;
                    
                }
                dp[i][j] = ans;
            }
        }
        if(dp[0][sum] == INT_MAX) return -1;
        return dp[0][sum];
    }
};