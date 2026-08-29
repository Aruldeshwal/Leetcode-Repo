class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0]; 
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] * nums[i];

        }
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] * nums[i];
        }
        vector<int> ans(n, 1);
        ans[0] = suffixSum[1];
        for(int i = 1; i < n - 1; i++) {
            ans[i] = suffixSum[i + 1] * prefixSum[i - 1];
        }
        ans[n - 1] = prefixSum[n - 2];
        return ans;
    }
};