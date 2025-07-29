class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();

        // dp[i][j] = true if s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(n1 + 1, vector<bool> (n2 + 1, false));
        dp[0][0] = true;  // empty string matches empty pattern

        // Fill first row: matching empty string with pattern
        for(int i = 1; i <= n2; i++){
            bool flag = true;

            // Check if p[0...i-1] contains only '*' to match empty string
            for(int j = 1; j <= i; j++){
                if(p[j - 1] != '*') { 
                    flag = false;
                    break;            
                }
            }
            dp[0][i] = flag;
        }

        // Fill rest of the dp table
        for(int index1 = 1; index1 <= n1; index1++) {
            for(int index2 = 1; index2 <= n2; index2++) {
                // Characters match or pattern has '?'
                if(s[index1 - 1] == p[index2 - 1] || p[index2 - 1] == '?') {
                    dp[index1][index2] = dp[index1 - 1][index2 - 1];
                }
                // Pattern has '*': match zero chars or one/more chars
                else if(p[index2 - 1] == '*') {
                    dp[index1][index2] = dp[index1][index2 - 1]     // '*' matches empty
                                       || dp[index1 - 1][index2];   // '*' matches s[index1 - 1]
                }
                // No match
                else dp[index1][index2] = false;
            }
        }

        // Final answer: full string vs full pattern
        return dp[n1][n2];  
    }
};
