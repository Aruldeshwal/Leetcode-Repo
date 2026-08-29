class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        
        for(string str : strs) {
            string temp = str;
            sort(str.begin(), str.end());
            mp[str].push_back(temp);
        }
        for(auto &it : mp) {
            vector<string> res;
            for(string i : it.second) {
                res.push_back(i);
            }
            ans.push_back(res);
        }
        return ans;
        

    }
};