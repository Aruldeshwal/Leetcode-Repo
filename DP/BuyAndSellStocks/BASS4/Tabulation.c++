class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // 3D DP table:
        // dp[index][buy][target] = max profit from day `index` with `buy` state and `target` transactions left
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // Iterate from last day to first
        for (int index = n - 1; index >= 0; index--) {
            // Iterate over both states: 1 = buy allowed, 0 = sell allowed
            for (int buy = 0; buy <= 1; buy++) {
                // Loop through number of transactions left (must be at least 1 to perform any action)
                for (int target = 1; target <= k; target++) {
                    int include = 0, exclude = 0;

                    if (buy) {
                        // Option 1: Buy the stock today and go to sell state
                        include = dp[index + 1][0][target] - prices[index];

                        // Option 2: Skip buying today
                        exclude = dp[index + 1][1][target];
                    } else {
                        // Option 1: Sell the stock today and reduce the transaction count
                        include = dp[index + 1][1][target - 1] + prices[index];

                        // Option 2: Skip selling today
                        exclude = dp[index + 1][0][target];
                    }

                    // Store the maximum of including or excluding today’s action
                    dp[index][buy][target] = max(include, exclude);
                }
            }
        }

        // Final answer: max profit starting from day 0 with buy permission and k transactions
        return dp[0][1][k];
    }
};
