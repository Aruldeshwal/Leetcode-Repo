class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for(int index = n - 1; index >= 0; index--) {
            for(string word : wordDict) {
                int i = 0;
                int m = word.size();
                while(i + index < n && i < m && s[i + index] == word[i]) {
                    i++;
                }
                if(i != m) continue;
                if(dp[index + i]) {
                    dp[index] = 1;
                    break;
                }
            }
        }
        return dp[0];
    }
};