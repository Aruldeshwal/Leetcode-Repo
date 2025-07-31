class Solution {
  public:
    string reverseWords(string &s) {
        string ans = "";
        string temp = "";
        int i = s.length() - 1;

        while (i >= 0) {
            if (s[i] == '.') {
                // If we have a word collected, reverse and add it
                if (!temp.empty()) {
                    reverse(temp.begin(), temp.end());
                    if (!ans.empty()) ans += '.';
                    ans += temp;
                    temp = "";
                }
                // Skip consecutive dots
                while (i >= 0 && s[i] == '.') i--;
            } else {
                temp += s[i];
                i--;
            }
        }
        // Add the last word if any
        if (!temp.empty()) {
            reverse(temp.begin(), temp.end());
            if (!ans.empty()) ans += '.';
            ans += temp;
        }
        return ans;
    }
};
