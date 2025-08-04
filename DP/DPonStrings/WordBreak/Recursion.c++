class Solution {
public:
    // Recursive function to check if s[index:] can be segmented using wordDict
    bool solve(string &s, vector<string> &wordDict, int index) {
        // Base case: if we reached end of string, it's fully segmented
        if(index >= s.size()) return true;

        bool ans = false;

        // Try every word in the dictionary
        for(int i = 0; i < wordDict.size(); i++) {
            string currWord = wordDict[i];
            int wordLen = currWord.length();

            // Extract substring from current index with length = current word
            string indexWord = s.substr(index, wordLen);

            // If word matches, recursively check remaining string
            if(currWord == indexWord) {
                ans = ans || solve(s, wordDict, index + wordLen);
            }
        }

        // Return true if any path led to a valid segmentation
        return ans;
    }

    // Main function that starts recursion from index 0
    bool wordBreak(string s, vector<string>& wordDict) { 
        return solve(s, wordDict, 0);
    }
};
