class Solution {
public:
    // Recursive function to find the minimum money needed to guarantee a win
    int solve(int start, int end, vector<vector<int>> &dp) {
        // Base case: no cost when start >= end (no numbers left or only one number)
        if(start >= end) return 0;

        // if dp vector is altered, return the value
        if(dp[start][end] != -1) return dp[start][end];
        
        int ans = INT_MAX;

        // Try every number i in the range [start, end] as the guess
        for(int i = start; i <= end; i++) {
            // If we guess i, we pay i dollars and the worst case is either left or right subproblem
            int cost = i + max(solve(start, i - 1, dp), solve(i + 1, end, dp));

            // Choose the minimum among all possible guesses
            ans = min(ans, cost);
        }

        return dp[start][end] = ans;
    }

    // Main function to start the recursion from 1 to n
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return solve(1, n, dp); 
    }
};
