class Solution {
public:
    // Recursive function to find the minimum number of coins to make 'amount'
    int solve(vector<int> &coins, int amount) {
        // Base case: if amount is exactly 0, we need 0 coins
        if (amount == 0) return 0;

        // Base case: if amount is negative, we can't form it, return INT_MAX (invalid)
        if (amount < 0) return INT_MAX;

        int ans = INT_MAX; // Initialize answer to max, so we can use min() properly

        // Try every coin
        for (int i = 0; i < coins.size(); i++) {
            // Recursive call: try reducing current coin value from amount
            int res = solve(coins, amount - coins[i]);

            // Only update answer if the recursive call didn’t return an invalid result
            if (res != INT_MAX) {
                ans = min(ans, res + 1); // +1 because we used one coin here
            }
        }

        // Return the minimum number of coins needed for this amount
        return ans;
    }

    // Main function called with input
    int coinChange(vector<int>& coins, int amount) {
        int res = solve(coins, amount); // Solve using recursion

        // If result is still INT_MAX, that means amount can't be formed
        return res == INT_MAX ? -1 : res;
    }
};
