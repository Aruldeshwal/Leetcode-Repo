class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // Only store two 1D rows: current and next
        vector<int> curr(n + 1, 0);  // Current row (for start index)
        vector<int> next(n + 1, 0);  // Next row (for start + 1)

        // Fill DP bottom-up, starting from end of string
        for(int start = n - 1; start >= 0; start--) {
            for(int end = start; end <= n - 1; end++) {
                int ans = 0;

                // Base case: single character is a palindrome of length 1
                if(start == end) {
                    curr[end] = 1;
                    continue;
                }

                // If characters match, include both ends and add result of inner substring
                if(s[start] == s[end]) {
                    ans = 2 + next[end - 1];
                }
                else {
                    // Else, skip either start or end and take the maximum result
                    ans = max(next[end], curr[end - 1]);
                }

                curr[end] = ans;  // Store the computed answer
            }

            // Move current row to next for the next iteration
            next = curr;
        }

        // Final answer for full string is stored in next[n - 1]
        return next[n - 1];
    }
};
