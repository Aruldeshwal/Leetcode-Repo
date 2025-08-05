class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Phase 1: Finding the intersection point inside the cycle
        int slow = nums[0];          // Start slow from first element
        int fast = nums[nums[0]];    // Start fast two steps ahead

        while (slow != fast) {
            slow = nums[slow];           // Move slow by 1 step
            fast = nums[nums[fast]];     // Move fast by 2 steps
        }

        // Phase 2: Finding the entry point of the cycle (duplicate number)
        slow = 0;                        // Reset slow to beginning

        while (slow != fast) {
            slow = nums[slow];          // Move both pointers by 1 step
            fast = nums[fast];          // They will meet at the duplicate
        }

        return slow; // or fast → both are at the duplicate number
    }
};
