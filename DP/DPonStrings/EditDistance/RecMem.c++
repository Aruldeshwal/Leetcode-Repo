class Solution {
public:
    // Recursive function with memoization to calculate minimum edit distance
    int solve(string &word1, string &word2, int index1, int index2, vector<vector<int>> &dp) {
        // If word1 is exhausted, insert all remaining characters of word2
        if(word1.size() == index1){
            return word2.size() - index2;
        }

        // If word2 is exhausted, delete all remaining characters of word1
        if(word2.size() == index2) {
            return word1.size() - index1;
        }

        // Return memoized result if already calculated
        if(dp[index1][index2] != -1) return dp[index1][index2];

        // If characters match, move both pointers ahead (no cost)
        if(word1[index1] == word2[index2])
            return dp[index1][index2] = solve(word1, word2, index1 + 1, index2 + 1, dp);

        // Try all three operations and take minimum:
        // 1. Insert word2[index2] at word1[index1]
        int insertion = 1 + solve(word1, word2, index1, index2 + 1, dp);

        // 2. Delete word1[index1]
        int deletion = 1 + solve(word1, word2, index1 + 1, index2, dp);

        // 3. Replace word1[index1] with word2[index2]
        int replace = 1 + solve(word1, word2, index1 + 1, index2 + 1, dp);

        // Store and return the minimum of all three operations
        return dp[index1][index2] = min({insertion, deletion, replace});
    }

    // Main function to initialize DP and start the recursion
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        // dp[i][j] stores the result for word1[i:] and word2[j:]
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        return solve(word1, word2, 0, 0, dp);
    }
};
