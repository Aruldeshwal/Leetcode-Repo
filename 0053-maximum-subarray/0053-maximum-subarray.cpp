class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int n = nums.size();
        int i = 0;
        while(i < n) {
            int sum = 0;
            int j = i;
            while(j < n && sum >= 0) {
                sum += nums[j++];
                maxSum = max(sum, maxSum);
            }
            i = j;
        }
        return maxSum;
    }
};