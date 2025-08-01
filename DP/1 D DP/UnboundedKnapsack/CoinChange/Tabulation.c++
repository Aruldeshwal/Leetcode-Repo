class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] will store the minimum number of coins needed to make amount 'i'
        vector<int> dp(amount + 1, INT_MAX);

        int n = coins.size();

        // Base case: To make amount 0, we need 0 coins
        dp[0] = 0;

        // Loop through every amount from 1 to target 'amount'
        for (int money = 1; money <= amount; money++) {
            int ans = INT_MAX;

            // Try every coin to see if it can contribute to the current 'money'
            for (int i = 0; i < n; i++) {
                // If coin value is bigger than 'money', skip it
                if (coins[i] > money) continue;

                // dp[money - coins[i]] gives the answer for the sub-amount
                int res = dp[money - coins[i]];

                // If sub-amount is valid, update the minimum coins required
                if (res != INT_MAX) {
                    ans = min(ans, res + 1); // +1 for using the current coin
                }
            }

            // Store the best answer for current 'money' amount
            dp[money] = ans;
        }

        // If dp[amount] is still INT_MAX, it means we can't form that amount
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
