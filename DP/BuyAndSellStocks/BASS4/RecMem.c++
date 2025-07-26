class Solution {
public:
    // Recursive function to compute max profit
    // prices: array of stock prices
    // index: current day
    // buy: 1 if we can buy, 0 if we can sell
    // target: how many transactions (buy+sell pairs) are left
    // dp: 3D memoization table to store results and avoid recomputation
    int solve(vector<int> &prices, int index, int buy, int target, vector<vector<vector<int>>> &dp) {
        // Base case: no transactions left or end of price list
        if(target == 0 || index == prices.size()) return 0;

        // If result already computed, return it
        if(dp[index][buy][target] != -1) return dp[index][buy][target];

        int include = 0, exclude = 0;

        if(buy) {
            // Option 1: Buy on this day → reduce money, switch to sell state
            include = solve(prices, index + 1, 0, target, dp) - prices[index];

            // Option 2: Skip this day, stay in buy state
            exclude = solve(prices, index + 1, 1, target, dp);
        } else {
            // Option 1: Sell on this day → earn money, reduce target, switch to buy state
            include = solve(prices, index + 1, 1, target - 1, dp) + prices[index];

            // Option 2: Skip this day, stay in sell state
            exclude = solve(prices, index + 1, 0, target, dp);
        }

        // Store and return the max of including or excluding the current day
        return dp[index][buy][target] = max(include, exclude);
    }

    // Main function to start the DP recursion
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // Initialize a 3D DP table with -1 for memoization
        // Dimensions: n days × 2 states (buy/sell) × k+1 transactions
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        // Start recursion from day 0, in buy state, with k transactions left
        return solve(prices, 0, 1, k, dp);
    }
};
