class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; // Max Heap; stores all elements → O(n) space

        // Push all elements into the heap → O(n log n) time
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]); // Each push is O(log n)
        }

        // Remove the largest k-1 elements → O(k log n) time
        for(int i = 1; i < k; i++) {
            pq.pop(); // Each pop is O(log n)
        }

        // Top of heap is now the k-th largest element → O(1) time
        return pq.top();
    }
};

/*
Overall Time Complexity:
- Building the heap: O(n log n)
- Removing k-1 elements: O(k log n)
- Total: O(n log n) (dominant term when n >> k)

Overall Space Complexity:
- Heap stores all n elements: O(n)
*/


