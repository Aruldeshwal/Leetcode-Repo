class Solution {
public:

    // Recursive function to calculate max profit
    int solve(vector<int> &prices, int fee, int index, int buy, vector<vector<int>> &dp) {
        // Base case: if we've gone past the last day, no profit can be made
        if(index == prices.size()) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];

        int include = 0, exclude = 0;

        // If we can buy on this day
        if(buy) {
            // Option 1: Buy the stock → subtract price from profit and switch to "sell" mode
            include = solve(prices, fee, index + 1, 0, dp) - prices[index];
            // Option 2: Skip buying, stay in "buy" mode
            exclude = solve(prices, fee, index + 1, 1, dp);
        }
        else {
            // If we are in "sell" mode

            // Option 1: Sell the stock → add price - fee to profit and switch to "buy" mode
            include = solve(prices, fee, index + 1, 1, dp) + prices[index] - fee;
            // Option 2: Skip selling, stay in "sell" mode
            exclude = solve(prices, fee, index + 1, 0, dp);
        }

        // Return the max profit between the two options
        return dp[index][buy] = max(include, exclude);
    }

    // Entry point: start from index 0 with buying option
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        return solve(prices, fee, 0, 1, dp);
    }
};
