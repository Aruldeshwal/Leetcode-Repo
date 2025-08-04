class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(); 
        
        // dp[i] means: can the substring s[i:] be segmented using the dictionary
        vector<bool> dp(n + 1, false);  
        dp[n] = true; // Base case: empty string can always be segmented

        // Loop from the end of the string to the beginning
        for(int index = n - 1; index >= 0; index--) {
            bool ans = false;

            // Try matching each word in the dictionary starting at index
            for(int i = 0; i < wordDict.size(); i++) {
                string currWord = wordDict[i];
                int wordLen = currWord.length();

                // Make sure the word fits within the bounds of the string
                if(index + wordLen <= n) {
                    // Get the substring of length wordLen from index
                    string indexWord = s.substr(index, wordLen);

                    // If it matches the dictionary word, check if remaining string can be segmented
                    if(currWord == indexWord) {
                        ans = ans || dp[index + wordLen];
                    }
                }
            }

            // Save result: can s[index:] be segmented?
            dp[index] = ans;
        }

        // Final answer: can the whole string s[0:] be segmented?
        return dp[0];
    }
};
