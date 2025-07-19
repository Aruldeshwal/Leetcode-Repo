class Solution {
public:
    bool equalPartition(vector<int>& arr) {
        // First, we calculate the grand total of all elements within the array.
        int total = 0;
        for(int ele : arr){
            total += ele;
        }
        
        int n = arr.size();
        // An early and crucial exit condition: If the total 'sum' of the array
        // is an odd number, it is mathematically impossible to divide it into two
        // subsets that possess equal sums. For instance, [1, 3, 5] sums to 9,
        // which cannot be halved into two equal integer values.
        if(total % 2 != 0) return false;
        
        // since two arguments are changing, we provide 2D dp
        vector<vector<int>> dp(n + 1, vector<int> (total / 2 + 1, 0));
        
        // since this was the element that resulted in true during recursion
        dp[n][0] = true;
        
        // current index from n - 1 to 0 to emulate bottom up approach from recursion counterpart
        for(int curr = n - 1; curr >= 0; curr--){
            // similarly, sum from 0 to total / 2
            for(int sum = 0; sum <= total / 2; sum++){
                
                //include current element as dp element
                bool include = 0;
                
                if (sum - arr[curr] >= 0) {
                    // Ensure that 'sum - arr[curr]' is a valid index.
                    include = nextArr[sum - arr[curr]];
                }
            
                
                //exclude current element as dp element
                bool exclude = dp[curr + 1][sum];
        
                // store result in current element of dp
                dp[curr][sum] = include || exclude;
            }
        }
        //return the dp element at upper limit of the loops
        return dp[0][total / 2];
    }
};
