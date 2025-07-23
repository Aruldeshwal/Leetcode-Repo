class Solution {
public:
    // Recursive function to calculate min cost for arr[left...right]
    int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right){
        // Base case: only one leaf, no internal node to form
        if(left == right) return 0;

        int ans = INT_MAX;

        // Try all possible partitions between left and right
        for(int i = left; i < right; i++){
            // Cost = max in left subarray * max in right subarray
            // + cost of building left tree + cost of building right tree
            int cost = maxi[{left, i}] * maxi[{i + 1, right}]
                     + solve(arr, maxi, left, i)
                     + solve(arr, maxi, i + 1, right);

            // Take the min across all partitions
            ans = min(ans, cost);
        }

        return ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        map<pair<int, int>, int> maxi;  // Store max leaf value in arr[i...j]
        int n = arr.size();

        // Precompute max values for all subarrays [i...j]
        for(int i = 0; i < n; i++) { 
            maxi[{i, i}] = arr[i];  // Base case: single element
            for(int j = i + 1; j < n; j++) {
                // max of arr[i...j] = max(arr[i...j-1], arr[j])
                maxi[{i, j}] = max(maxi[{i, j - 1}], arr[j]);
            }
        }

        // Start recursive solve from full array
        return solve(arr, maxi, 0, n - 1);
    }
};
