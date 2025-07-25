class Solution {
public:
    // Recursive helper to calculate max profit with a transaction limit
    int solve(vector<int> &prices, int index, int limit, int buy) {
        // Base case: if we've gone through all days or used up transactions
        if(index == prices.size()) return 0;
        if(limit == 0) return 0;

        int include = 0, exclude = 0;

        if(buy) {
            // Option 1: Buy the stock now → move to sell state
            include = solve(prices, index + 1, limit, 0) - prices[index];
            // Option 2: Skip buying
            exclude = solve(prices, index + 1, limit, 1);
        }
        else {
            // Option 1: Sell now → reduce transaction limit, go back to buy state
            include = solve(prices, index + 1, limit - 1, 1) + prices[index];
            // Option 2: Skip selling
            exclude = solve(prices, index + 1, limit, 0);
        }

        // Return the better profit
        return max(include, exclude);
    }

    // Start recursion from index 0, 2 transactions allowed, and buy state = true
    int maxProfit(vector<int>& prices) {
        return solve(prices, 0, 2, 1);
    }
};
