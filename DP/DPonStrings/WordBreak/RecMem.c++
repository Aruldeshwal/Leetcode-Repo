class Solution {
public:
    // Helper function to recursively check if s[index:] can be segmented
    bool solve(string &s, vector<string> &wordDict, int index, vector<int> &dp) {
        // Base case: reached end of string successfully
        if(index >= s.size()) return true;

        // If result already computed, return it (memoization)
        if(dp[index] != -1) return dp[index];

        bool ans = false;

        // Try matching each word in dictionary from current index
        for(int i = 0; i < wordDict.size(); i++) {
            string currWord = wordDict[i];
            int wordLen = currWord.length();

            // Get substring from s starting at index with length of currWord
            string indexWord = s.substr(index, wordLen);

            // If word matches, recursively check the rest of the string
            if(currWord == indexWord) {
                ans = ans || solve(s, wordDict, index + wordLen, dp);
            }
        }

        // Store the result in dp and return it
        return dp[index] = ans;
    }

    // Main function to initialize dp and start recursion from index 0
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(); 
        vector<int> dp(n + 1, -1); // dp[i] stores whether s[i:] can be segmented
        return solve(s, wordDict, 0, dp);
    }
};
