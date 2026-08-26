class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n + 2, 0);
        vector<int> dp2(n + 2, 0);
        for(int i = n - 1; i >= 0; i--) {
            int include = nums[i] + dp1[i + 2];
            int exclude = dp1[i + 1];
            dp1[i] = max(include, exclude);
        }
        for(int i = n - 1; i >= 1; i--) {
            int include = nums[i] + dp2[i + 2];
            int exclude = dp2[i + 1];
            dp2[i] = max(include, exclude);
        }
        return max(dp1[0], dp2[1]);
    }
};