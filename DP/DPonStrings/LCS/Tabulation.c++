class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        // Create a 2D dp table initialized to 0
        // dp[i][j] = LCS of text1[i:] and text2[j:]
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));

        // Fill the table from bottom-right to top-left
        for(int index1 = n1 - 1; index1 >= 0; index1--) {
            for(int index2 = n2 - 1; index2 >= 0; index2--) {
                int ans = 0;

                // If characters match, take 1 + diagonal value
                if(text1[index1] == text2[index2]){
                    ans = 1 + dp[index1 + 1][index2 + 1];
                }
                else {
                    // Else, take max of skipping one character from either string
                    ans = max(dp[index1 + 1][index2], dp[index1][index2 + 1]);
                }

                dp[index1][index2] = ans;  // Store the result
            }
        }

        // Final answer is the LCS of full strings
        return dp[0][0];
    }
};
