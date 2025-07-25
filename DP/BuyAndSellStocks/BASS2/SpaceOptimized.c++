class Solution {
public:
    // Main function that starts the recursion with buy = true
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> next(2, 0);
        vector<int> curr(2, 0);
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy < 2; buy++) {
                int include = 0, exclude = 0;

                // If we are allowed to buy
                if (buy) {
                    // Option 1: Buy now, subtract price and set next move to
                    // sell
                    include = next[0] - prices[index];
                    // Option 2: Skip buying at this index
                    exclude = next[1];
                } else { // If we need to sell
                    // Option 1: Sell now, add price and set next move to buy
                    include = next[1] + prices[index];
                    // Option 2: Skip selling at this index
                    exclude = next[0];
                }

                // Return the better of the two choices
                curr[buy] = max(include, exclude);
            }
            next = curr;
        }
        return next[1];
    }
};
