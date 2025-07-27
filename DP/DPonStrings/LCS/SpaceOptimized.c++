class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();

        // We only need two rows at a time: current and next
        vector<int> curr(n2 + 1, 0);  // current row
        vector<int> next(n2 + 1, 0);  // next row (i+1)

        // Fill from bottom-right to top-left
        for(int index1 = n1 - 1; index1 >= 0; index1--) {
            for(int index2 = n2 - 1; index2 >= 0; index2--) {
                int ans = 0;

                // If characters match, take 1 + diagonal (next row, next col)
                if(text1[index1] == text2[index2]){
                    ans = 1 + next[index2 + 1];
                }
                else {
                    // Else, take max of:
                    // - skipping text1 char (next row same col)
                    // - skipping text2 char (same row next col)
                    ans = max(next[index2], curr[index2 + 1]);
                }

                curr[index2] = ans;  // Store in current row
            }
            next = curr;  // Move current row to next for next iteration
        }

        // Final result is in next[0], which holds dp[0][0]
        return next[0];
    }
};
