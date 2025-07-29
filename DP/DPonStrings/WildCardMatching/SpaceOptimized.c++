class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        vector<bool> curr(n2 + 1, false);
        vector<bool> prev(n2 + 1, false);
        prev[0] = true;
        for(int i = 1; i <= n2; i++){
            bool flag = true;
            for(int j = 1; j <= i; j++){
                if(p[j - 1] != '*') { 
                    flag = false;
                    break;            
                }
            }
            prev[i] = flag;
        }
        for(int index1 = 1; index1 <= n1; index1++) {
            for(int index2 = 1; index2 <= n2; index2++) {
                if(s[index1 - 1] == p[index2 - 1] || p[index2 - 1] == '?') {
                    curr[index2] = prev[index2 - 1];
                }
                else if(p[index2 - 1] == '*') {
                    curr[index2] = curr[index2 - 1] || prev[index2];
                }
                else curr[index2] = false;
            }
            prev = curr;
        }
        return prev[n2];  
    }
};
