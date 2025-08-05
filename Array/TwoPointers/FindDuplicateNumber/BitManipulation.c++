class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int bit_max = 31;

        // Find the highest bit needed (most significant bit in n - 1)
        while (((n - 1) >> bit_max) == 0) {
            bit_max -= 1;
        }

        // Loop over each bit position from 0 to bit_max
        for (int bit = 0; bit <= bit_max; bit++) {
            int x = 0, y = 0;

            // Count how many numbers in nums have this bit set (x)
            // and how many numbers from 1 to n-1 have this bit set (y)
            for (int i = 0; i < n; i++) {
                if ((nums[i] & (1 << bit)) != 0) {
                    x += 1;
                }
                if (i >= 1 && ((i & (1 << bit)) != 0)) {
                    y += 1;
                }
            }

            // If more numbers in nums have this bit set than expected,
            // it means this bit is part of the duplicate number
            if (x > y) {
                ans |= 1 << bit;  // Set this bit in the answer
            }
        }

        return ans;  // The reconstructed duplicate number
    }
};
