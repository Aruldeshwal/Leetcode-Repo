class Solution {
public:
    // Recursive function to find LPS length between indices [start...end]
    int solve(string &s, int start, int end){
        // Base case: invalid range
        if(start > end) return 0;

        // Base case: single character is a palindrome of length 1
        if(start == end) return 1;

        int ans = 0;

        // If characters at both ends match, include them in result
        if(s[start] == s[end]) {
            ans = 2 + solve(s, start + 1, end - 1);  // shrink both sides
        }
        else {
            // Else, try skipping one character from either end and take the max
            ans = max(solve(s, start + 1, end), solve(s, start, end - 1));
        }

        return ans;
    }

    // Main function: call solve on the full string
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        return solve(s, 0, n - 1);
    }
};
