class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        unordered_set<int> set;
        for(int num : nums) {
            set.insert(num);
        }
        int firstElement = lower;
        for(int i = lower; i <= upper; i++) {   
            if(set.find(i) != set.end()) {
                if(i > firstElement) {
                    ans.push_back({firstElement, i - 1});
                }
                firstElement = i + 1;
            }
        }
        if(set.find(upper) == set.end()) {
            ans.push_back({firstElement, upper});
        }
        return ans;
    }
};