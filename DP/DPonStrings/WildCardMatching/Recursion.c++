class Solution {
public:
    // Recursive function to check if s[0...index1] matches p[0...index2]
    bool solve(string &s, string &p, int index1, int index2) {
        // Both strings fully matched
        if(index1 < 0 && index2 < 0) return true;

        // Pattern exhausted but string not -> mismatch
        if(index1 >= 0 && index2 < 0) return false;

        // String exhausted, check if remaining pattern chars are all '*'
        if(index1 < 0 && index2 >= 0){
            for(int i = 0; i <= index2; i++){
                if(p[i] != '*') return false;
            }
            return true;
        }  

        // Characters match or '?' matches any single character
        if(s[index1] == p[index2] || p[index2] == '?') {
            return solve(s, p, index1 - 1, index2 - 1);
        }
        // '*' can match 0 chars (move in pattern) or 1 char from string (move in string)
        else if(p[index2] == '*') {
            return solve(s, p, index1, index2 - 1)   // '*' = empty sequence
                || solve(s, p, index1 - 1, index2);  // '*' = one or more characters
        }
        // Characters don't match and no wildcard
        else return false;
    }

    // Entry point to start recursion
    bool isMatch(string s, string p) {
        return solve(s, p, s.size() - 1, p.size() - 1);  
    }
};
