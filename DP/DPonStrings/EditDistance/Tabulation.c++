class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();

        // dp[i][j] will represent the min operations to convert word1[i:] to word2[j:]
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Fill base cases:
        // If word1 is empty, we need to insert all characters from word2
        for(int j = 0; j <= n2; j++) {
            dp[n1][j] = n2 - j;
        }

        // If word2 is empty, we need to delete all characters from word1
        for(int i = 0; i <= n1; i++) {
            dp[i][n2] = n1 - i;
        }

        // Fill the dp table from bottom to top
        for(int i = n1 - 1; i >= 0; i--) {
            for(int j = n2 - 1; j >= 0; j--) {

                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1]; // characters match, no operation
                } else {
                    int insertOp = 1 + dp[i][j + 1];
                    int deleteOp = 1 + dp[i + 1][j];
                    int replaceOp = 1 + dp[i + 1][j + 1];
                    dp[i][j] = min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[0][0]; // final answer: convert full word1 to full word2
    }
};
