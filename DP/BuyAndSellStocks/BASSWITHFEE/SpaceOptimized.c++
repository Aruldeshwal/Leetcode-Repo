class Solution {
public:
    // Entry point: start from index 0 with buying option
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> next(2, 0);
        vector<int> curr(2, 0);
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                int include = 0, exclude = 0;

                // If we can buy on this day
                if (buy) {
                    // Option 1: Buy the stock → subtract price from profit and
                    // switch to "sell" mode
                    include = next[0] - prices[index];
                    // Option 2: Skip buying, stay in "buy" mode
                    exclude = next[1];
                } else {
                    // If we are in "sell" mode

                    // Option 1: Sell the stock → add price - fee to profit and
                    // switch to "buy" mode
                    include = next[1] + prices[index] - fee;
                    // Option 2: Skip selling, stay in "sell" mode
                    exclude = next[0];
                }

                // Return the max profit between the two options
                curr[buy] = max(include, exclude);
            }
            next = curr;
        }
        return next[1];
    }
};
