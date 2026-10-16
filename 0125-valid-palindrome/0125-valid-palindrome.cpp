class Solution {
public:
    bool isPalindrome(string s) {
        string st = "";
        for(char ch : s) {
            if(ch >= 'A' && ch <= 'Z') {
                ch = (ch - 'A') + 'a';
            }
            if(ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
                st += ch;
            }
        }
        int i = 0, j = st.size() - 1;
        while(i < j) {
            if(st[i++] != st[j--]) return false;
        }
        return true;
    }
};