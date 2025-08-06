class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // If the array has only one element, there's no next permutation
        if(n == 1) return;

        // Step 1: Find the first decreasing element from the end
        int i = n - 1;
        while(i > 0 && nums[i - 1] >= nums[i]) 
            i--;

        // If no such element is found, the array is in descending order
        // So just reverse it to get the smallest permutation
        if(i == 0) {
            int j = n - 1;
            while(i <= j) {
                swap(nums[i++], nums[j--]);
            }
            return;
        }

        // Step 2: Find the next greater element to the right of nums[i - 1]
        int j = n - 1;
        while(j >= i && nums[j] <= nums[i - 1]) 
            j--;

        // Step 3: Swap nums[i - 1] with nums[j]
        swap(nums[i - 1], nums[j]);

        // Step 4: Reverse the part from i to end to get the next smallest lexicographic order
        j = n - 1;
        while(i <= j) {
            swap(nums[i++], nums[j--]);
        }

        return;
    }
};
