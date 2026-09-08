class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        unordered_set<int> mp;
        for(int num : nums) {
            mp.insert(num);
        }
        vector<int> erased(101, 0);
        int uniqueNum = mp.size();
        while(i < n) {
            while(i < n - 1 && nums[i] == nums[i + 1])
                i++;
            if(mp.find(nums[i]) == mp.end() && !erased[nums[i]]) 
            {
                uniqueNum--;
                erased[nums[i]] = 1;
            }
            else {
                mp.erase(nums[i]);
            }
            i++;
        }
        return uniqueNum;
    }
};