class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min Heap; stores only the k largest elements → O(k) space
        priority_queue<int, vector<int>, greater<int>> pq;

        // Process each number in the array → O(n log k) time
        for(int num : nums) {
            pq.push(num); // O(log k) time for insertion

            // If heap grows larger than k, remove the smallest element → O(log k)
            if(pq.size() > k) {
                pq.pop();
            }
        }

        // Top of the heap is the k-th largest element → O(1) time
        return pq.top();
    }
};

/*
Overall Time Complexity:
- Each push/pop is O(log k), done for n elements → O(n log k)
- This is faster than O(n log n) when k << n

Overall Space Complexity:
- Heap stores at most k elements → O(k)
*/
