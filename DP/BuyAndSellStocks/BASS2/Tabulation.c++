class Solution {
public:
    // Main function that starts the recursion with buy = true
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                int include = 0, exclude = 0;

                // If we are allowed to buy
                if (buy) {
                    // Option 1: Buy now, subtract price and set next move to
                    // sell
                    include = dp[index + 1][0] - prices[index];
                    // Option 2: Skip buying at this index
                    exclude = dp[index + 1][1];
                } else { // If we need to sell
                    // Option 1: Sell now, add price and set next move to buy
                    include = dp[index + 1][1] + prices[index];
                    // Option 2: Skip selling at this index
                    exclude = dp[index + 1][0];
                }

                // Return the better of the two choices
                dp[index][buy] = max(include, exclude);
            }
        }
        return dp[0][1];
    }
};
