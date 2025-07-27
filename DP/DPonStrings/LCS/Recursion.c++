class Solution {
public:
    // Recursive function to calculate LCS starting from index1 and index2
    int solve(string &text1, string &text2, int index1, int index2){
        // Base case: if either string is exhausted, LCS is 0
        if(text1.size() == index1 || text2.size() == index2) return 0;

        int ans = 0;
        // If current characters match, include in LCS and move both indices
        if(text1[index1] == text2[index2]){
            ans += 1 + solve(text1, text2, index1 + 1, index2 + 1);
        }
        else {
            // Else, explore both possibilities:
            // 1. Move index1 (skip character in text1)
            // 2. Move index2 (skip character in text2)
            // Take the max of both
            ans += max(solve(text1, text2, index1 + 1, index2), solve(text1, text2, index1, index2 + 1));
        }

        return ans;
    }

    // Main function to start recursion from index 0 of both strings
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1, text2, 0, 0);
    }
};
