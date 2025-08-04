class Solution {
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp) {
        if (amount == 0) return 0;
        if (amount < 0) return INT_MAX;
        if (dp[amount] != -1) return dp[amount];

        int ans = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            int res = solve(coins, amount - coins[i], dp);
            if (res != INT_MAX) {
                ans = min(ans, res + 1);
            }
        }
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int res = solve(coins, amount, dp);
        return res == INT_MAX ? -1 : res;
    }
};
