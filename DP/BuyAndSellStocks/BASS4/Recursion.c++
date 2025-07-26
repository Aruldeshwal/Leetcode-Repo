class Solution {
public:
    // Recursive helper function to calculate max profit
    // prices: stock prices
    // index: current day
    // buy: whether we can buy (1) or sell (0)
    // target: number of transactions (buy + sell = 1 transaction)
    int solve(vector<int> &prices, int index, int buy, int target) {
        // Base case: if no transactions left or end of prices
        if(target == 0 || index == prices.size()) return 0;

        int include = 0, exclude = 0;

        if(buy) {
            // Option 1: Buy on this day and switch to sell mode
            include = solve(prices, index + 1, 0, target) - prices[index];

            // Option 2: Skip buying on this day
            exclude = solve(prices, index + 1, 1, target);
        }
        else {
            // Option 1: Sell on this day, reduce target (1 full transaction done)
            include = solve(prices, index + 1, 1, target - 1) + prices[index];

            // Option 2: Skip selling on this day
            exclude = solve(prices, index + 1, 0, target);
        }

        // Return max profit between including and excluding current day
        return max(include, exclude);
    }

    // Entry function to initiate recursion
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices, 0, 1, k);  // Start at day 0 with buy mode and k transactions
    }
};
