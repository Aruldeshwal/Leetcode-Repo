class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> pSum;
        pSum[0] = 1;
        int sum = 0;
        int c = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(pSum.find(sum - k) != pSum.end()) {
                c += pSum[sum - k];
            }
            pSum[sum]++;
        }
        return c;
    }
};