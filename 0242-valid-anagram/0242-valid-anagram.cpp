class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m) return false;
        vector<int> countS(26, 0);
        for(char ch : s) {
            countS[ch - 'a']++;
        }
        for(char ch : t) {
            countS[ch - 'a']--;
            if(countS[ch - 'a'] < 0) return false;
        }
        for(int count : countS) {
            if(count != 0) return false;
        }
        return true;
    }
};