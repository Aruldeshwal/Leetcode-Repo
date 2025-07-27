class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // dp[i][j] = length of longest palindromic subsequence in s[i...j]
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));

        // Fill the table from bottom to top, left to right
        for(int start = n - 1; start >= 0; start--){
            for(int end = start; end <= n - 1; end++){

                // Base case: single character is a palindrome of length 1
                if(start == end){
                    dp[start][end] = 1;
                    continue;
                }

                int ans = 0;

                // If characters match, take 2 + result from inner substring
                if(s[start] == s[end]) {
                    ans = 2 + dp[start + 1][end - 1];
                }
                else {
                    // Else, take the max by skipping either start or end
                    ans = max(dp[start + 1][end], dp[start][end - 1]);
                }

                dp[start][end] = ans;  // Store the answer
            }
        }

        // Final answer for full string is stored in dp[0][n-1]
        return dp[0][n - 1];
    }
};
