class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Binary search on the range of values [1, n - 1]
        int low = 1;
        int high = n - 1;

        while (low < high) {
            // Find the middle value of the current range
            int mid = low + (high - low) / 2;

            // Count how many numbers in the array are less than or equal to mid
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) {
                    count++;
                }
            }

            // If count > mid, duplicate must be in the range [low, mid]
            if (count > mid) {
                high = mid;
            } 
            // Else, duplicate must be in the range [mid + 1, high]
            else {
                low = mid + 1;
            }
        }

        // At the end, low == high, which is the duplicate number
        return low;
    }
};
