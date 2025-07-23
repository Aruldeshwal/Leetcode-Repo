class Solution {
public:
    // Main function to start the recursion from 1 to n
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));

        for(int start = n; start >= 1; start--) {
            
            for(int end = start + 1; end <= n; end++) {
                
                int ans = INT_MAX;
                
                // Try every number i in the range [start, end] as the guess
                for(int i = start; i <= end; i++) {
                    
                    // If we guess i, we pay i dollars and the worst case is either left or right subproblem
                    int cost = i + max(dp[start][i - 1], dp[i + 1][end]);

                    // Choose the minimum among all possible guesses
                    ans = min(ans, cost);
                }
                dp[start][end] = ans;
            }
        }
        return dp[1][n];
    }
};
