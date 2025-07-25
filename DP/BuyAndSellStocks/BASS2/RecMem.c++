class Solution {
public:
    // Recursive helper to calculate max profit
    int solve(vector<int> &prices, bool buy, int index, vector<vector<int>> &dp){
        // Base case: if index is out of bounds, no profit
        if(index == prices.size()) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];

        int include = 0, exclude = 0;

        // If we are allowed to buy
        if(buy){
            // Option 1: Buy now, subtract price and set next move to sell
            include = solve(prices, false, index + 1, dp) - prices[index];
            // Option 2: Skip buying at this index
            exclude = solve(prices, true, index + 1, dp);
        }
        else{ // If we need to sell
            // Option 1: Sell now, add price and set next move to buy
            include = solve(prices, true, index + 1, dp) + prices[index];
            // Option 2: Skip selling at this index
            exclude = solve(prices, false, index + 1, dp);
        }

        // Return the better of the two choices
        return dp[index][buy] = max(include, exclude);
    }

    // Main function that starts the recursion with buy = true
    int maxProfit(vector<int>& prices) {
        bool buy = true;
        vector<vector<int>> dp(prices.size() + 1, vector<int> (2, -1));
        return solve(prices, buy, 0, dp);
    }
};
