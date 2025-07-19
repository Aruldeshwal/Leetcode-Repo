class Solution {
public:
    //solve function decides if the function can be solved into a subset of the sum and a subset of elements that equal to the sum
    bool solve(vector<int> &arr, int curr, int sum, vector<vector<int>> &dp){
        // curr == arr.size() => we traversed entire array
        // sum == 0 => sum is 0 therefore, the subset has reached the required condition, hence return true
        if(curr == arr.size() && sum == 0) return true;
        
        // entire array is traversed but sum is not zero
        // if sum is below zero => the element we took resulted in wrong subset therefore return false
        if(curr == arr.size() || sum < 0) return false;
        
        //if dp element has been altered, return the element
        if(dp[curr][sum] != -1) return dp[curr][sum];
        
        // if current element is included, we move to next element while decreasing curr element from sum
        bool include = solve(arr, curr + 1, sum - arr[curr], dp);
        
        // if current element is excluded, we move to next element without touching the sum, hence, current element has no effect on sum 
        bool exclude = solve(arr, curr + 1, sum, dp);
        
        // store result in current element of dp
        // if either include or exclude yields a successful partition of subset, the function will return true
        return dp[curr][sum] = include || exclude;
    }

    bool equalPartition(vector<int>& arr) {
        // First, we calculate the grand total of all elements within the array.
        int sum = 0;
        for(int ele : arr){
            sum += ele;
        }
        
        // An early and crucial exit condition: If the total 'sum' of the array
        // is an odd number, it is mathematically impossible to divide it into two
        // subsets that possess equal sums. For instance, [1, 3, 5] sums to 9,
        // which cannot be halved into two equal integer values.
        if(sum % 2 != 0) return false;
        
        // since two arguments are changing, we provide 2D dp
        vector<vector<int>> dp(arr.size() + 1, vector<int> (sum / 2 + 1, -1));
        
        // Our objective is to ascertain if a subset exists that sums to precisely
        // half of the total array sum. If such a subset is discovered, then the
        // remaining elements of the array must, by logical deduction, also sum
        // to the other half, thereby forming two equally summed partitions.
        // We invoke our recursive 'solve' function, seeking a subset that sums
        // to 'sum / 2', commencing from the first element (index 0).
        return solve(arr, 0, sum / 2, dp);
    }
};
