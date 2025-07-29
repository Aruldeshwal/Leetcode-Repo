class Solution {
public:
    // Recursive function with memoization to check if s[0...index1] matches p[0...index2]
    bool solve(string &s, string &p, int index1, int index2, vector<vector<int>> &dp) {
        // Base case: both strings are exhausted
        if(index1 < 0 && index2 < 0) return true;

        // Pattern exhausted but string remains → mismatch
        else if(index1 >= 0 && index2 < 0) 
            return dp[index1 + 1][index2 + 1] = false;

        // String exhausted but pattern remains → valid only if all remaining chars are '*'
        else if(index1 < 0 && index2 >= 0){
            for(int i = 0; i <= index2; i++){
                if(p[i] != '*') 
                    return dp[index1 + 1][index2 + 1] = false;
            }
            return dp[index1 + 1][index2 + 1] = true;
        }  

        // Return cached result if already computed
        if(dp[index1 + 1][index2 + 1] != -1) 
            return dp[index1 + 1][index2 + 1];

        // Match if characters are same or pattern has '?'
        if(s[index1] == p[index2] || p[index2] == '?') {
            return dp[index1 + 1][index2 + 1] = solve(s, p, index1 - 1, index2 - 1, dp);
        }
        // '*' can match 0 characters (skip '*' in pattern) or 1+ characters (consume from string)
        else if(p[index2] == '*') {
            return dp[index1 + 1][index2 + 1] = 
                solve(s, p, index1, index2 - 1, dp)   // '*' matches empty
                || solve(s, p, index1 - 1, index2, dp); // '*' matches one char
        }
        // Characters don't match and no wildcard
        else return dp[index1 + 1][index2 + 1] = false;
    }

    // Entry point: initialize dp and start from end of both strings
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        // dp[i][j] stores result for s[i-1] and p[j-1]; size = (n1+1) x (n2+1)
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        return solve(s, p, n1 - 1, n2 - 1, dp);  
    }
};
