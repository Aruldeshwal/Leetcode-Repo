class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= 2; limit++) {
                    int include = 0, exclude = 0;
                    if (buy) {
                        // Option 1: Buy the stock now → move to sell state
                        include = next[0][limit] - prices[index];
                        // Option 2: Skip buying
                        exclude = next[1][limit];
                    } else {
                        // Option 1: Sell now → reduce transaction limit, go
                        // back to buy state
                        include = next[1][limit - 1] + prices[index];
                        // Option 2: Skip selling
                        exclude = next[0][limit];
                    }

                    // Return the better profit
                    curr[buy][limit] = max(include, exclude);
                }
                next = curr;
            }
        }
        return next[1][2];
    }
};
