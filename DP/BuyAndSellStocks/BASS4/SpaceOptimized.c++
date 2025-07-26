class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int target = 1; target <= k; target++) {
                    int include = 0, exclude = 0;
                    if (buy) {
                        include = next[0][target] - prices[index];
                        exclude = next[1][target];
                    } else {
                        include = next[1][target - 1] + prices[index];
                        exclude = next[0][target];
                    }
                    curr[buy][target] = max(include, exclude);
                }
                next = curr;
            }
        }
        return next[1][k];
    }
};
