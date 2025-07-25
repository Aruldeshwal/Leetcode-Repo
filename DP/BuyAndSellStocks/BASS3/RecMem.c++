class Solution {
public:
    // Recursive helper to calculate max profit with a transaction limit
    int solve(vector<int> &prices, int index, int limit, int buy, vector<vector<vector<int>>> &dp) {
        // Base case: if we've gone through all days or used up transactions
        if(index == prices.size()) return 0;
        if(limit == 0) return 0;
        if(dp[index][buy][limit] != -1) return dp[index][buy][limit];

        int include = 0, exclude = 0;

        if(buy) {
            // Option 1: Buy the stock now → move to sell state
            include = solve(prices, index + 1, limit, 0, dp) - prices[index];
            // Option 2: Skip buying
            exclude = solve(prices, index + 1, limit, 1, dp);
        }
        else {
            // Option 1: Sell now → reduce transaction limit, go back to buy state
            include = solve(prices, index + 1, limit - 1, 1, dp) + prices[index];
            // Option 2: Skip selling
            exclude = solve(prices, index + 1, limit, 0, dp);
        }

        // Return the better profit
        return dp[index][buy][limit] = max(include, exclude);
    }

    // Start recursion from index 0, 2 transactions allowed, and buy state = true
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int> (3, -1)));
        return solve(prices, 0, 2, 1, dp);
    }
};
