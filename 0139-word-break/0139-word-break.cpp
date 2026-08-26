class Solution {
public:
    bool solve(string s, vector<string> &wordDict, int index, vector<int> &dp) {
        if(index == s.size()) return dp[index] = false;
        if(dp[index] != -1) return dp[index];
        bool ans = false;
        for(string word : wordDict) {
            int i = 0;
            while(i + index < s.size() && i < word.size() && s[i + index] == word[i]) {
                i++;
            }
            if(i != word.size()) continue;
            if(i + index == s.size()) ans = true;
            else ans = ans || solve(s, wordDict, index + i, dp);
        }
        return dp[index] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(s, wordDict, 0, dp);
    }
};