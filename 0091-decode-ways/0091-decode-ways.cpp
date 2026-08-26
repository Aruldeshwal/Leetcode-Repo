class Solution {
public:
    int solve(const string &s, int index, vector<int> &dp) {
        if(index == s.size()) return 1;
        if(s[index] == '0') return 0;
        
        if(dp[index] != -1) return dp[index];
        int ways = solve(s, index + 1, dp);
        if(index + 1 < s.size()) {
            int twoDigit = (s[index] - '0') * 10 + (s[index + 1] - '0');
            if(twoDigit <= 26) {
                ways += solve(s, index + 2, dp);
            }
        }
        return dp[index] = ways;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};