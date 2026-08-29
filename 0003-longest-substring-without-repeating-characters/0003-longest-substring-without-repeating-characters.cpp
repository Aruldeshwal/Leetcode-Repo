class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int num = 0;
        int uniqueElements = 0;
        int n = s.size();
        int j = 0;
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
            if(mp[s[i]] == 1) {
                uniqueElements++;
                num = max(num, uniqueElements);
            }
            while(j < n && mp[s[i]] > 1) {
                mp[s[j]]--;
                if(mp[s[j]] == 0) uniqueElements--;
                j++;
            }

        }
        return num;
    }
};