class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int next = 0; 
        int curr = 0; 
        
        for(int i = n - 1; i >= 0; i--) {
            int include = nums[i] + next;
            int exclude = curr;
            
            int temp = curr;
            curr = max(include, exclude);
            next = temp;
        }
        
        return curr;
    }
};