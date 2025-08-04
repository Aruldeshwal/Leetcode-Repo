class Solution {
public:
    // Recursive function to find the maximum amount that can be robbed
    int solve(vector<int> &nums, int index) {
        // Base case: if index goes out of bounds, no money to rob
        if(index >= nums.size()) return 0;

        // Option 1: Rob current house and move to index + 2
        int include = nums[index] + solve(nums, index + 2);

        // Option 2: Skip current house and move to index + 1
        int exclude = solve(nums, index + 1);

        // Return the maximum money that can be robbed from both options
        return max(include, exclude);
    }

    // Main function to initiate the robbery from the first house
    int rob(vector<int>& nums) {
        return solve(nums, 0);
    }
};
