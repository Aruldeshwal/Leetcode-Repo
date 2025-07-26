class Solution {
public:
    // Entry point: start from index 0 with buying option
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int include = 0, exclude = 0;

                // If we can buy on this day
                if (buy) {
                    // Option 1: Buy the stock → subtract price from profit and
                    // switch to "sell" mode
                    include = dp[index + 1][0] - prices[index];
                    // Option 2: Skip buying, stay in "buy" mode
                    exclude = dp[index + 1][1];
                } else {
                    // If we are in "sell" mode

                    // Option 1: Sell the stock → add price - fee to profit and
                    // switch to "buy" mode
                    include = dp[index + 1][1] + prices[index] - fee;
                    // Option 2: Skip selling, stay in "sell" mode
                    exclude = dp[index + 1][0];
                }

                // Return the max profit between the two options
                dp[index][buy] = max(include, exclude);
            }
        }
        return dp[0][1];
    }
};
