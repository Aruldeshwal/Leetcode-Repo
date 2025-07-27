class Solution {
public:
    int solve(string &s, int start, int end, vector<vector<int>> &dp) {
        if(start > end) return 0;
        if(start == end) return 1;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = 0;
        if(s[start] == s[end]) {
            ans += 2 + solve(s, start + 1, end - 1, dp);
        }
        else ans += max(solve(s, start + 1, end, dp), solve(s, start, end - 1, dp));
        return dp[start][end] = ans;
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return solve(s, 0, n - 1, dp);
    }
};
