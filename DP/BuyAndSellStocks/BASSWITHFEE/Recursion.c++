class Solution {
public:

    // Recursive function to calculate max profit
    int solve(vector<int> &prices, int fee, int index, int buy) {
        // Base case: if we've gone past the last day, no profit can be made
        if(index == prices.size()) return 0;

        int include = 0, exclude = 0;

        // If we can buy on this day
        if(buy) {
            // Option 1: Buy the stock → subtract price from profit and switch to "sell" mode
            include = solve(prices, fee, index + 1, 0) - prices[index];
            // Option 2: Skip buying, stay in "buy" mode
            exclude = solve(prices, fee, index + 1, 1);
        }
        else {
            // If we are in "sell" mode

            // Option 1: Sell the stock → add price - fee to profit and switch to "buy" mode
            include = solve(prices, fee, index + 1, 1) + prices[index] - fee;
            // Option 2: Skip selling, stay in "sell" mode
            exclude = solve(prices, fee, index + 1, 0);
        }

        // Return the max profit between the two options
        return max(include, exclude);
    }

    // Entry point: start from index 0 with buying option
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices, fee, 0, 1);
    }
};
