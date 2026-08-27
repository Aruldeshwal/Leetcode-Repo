class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int jump = nums[0];
        int minJumps = 1;
        int prevJump = nums[0];
        for(int i = 1; i < n - 1; i++) {
            jump--;
            prevJump = max(prevJump - 1, nums[i]);
            if(jump == 0) {
                jump = prevJump;
                minJumps++;
            }
        }
        return minJumps;
    }
};