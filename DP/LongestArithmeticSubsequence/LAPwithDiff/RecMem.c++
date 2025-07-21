class Solution {
public:
    int solve(vector<int>& arr, int diff, int index, vector<int> &dp){

        // if index reaches negative value, we return zero
        if(index < 0) return 0;

        // if current dp element has been altered, return the element
        if(dp[index] != -1) return dp[index];

        // store max ans to return on recursion
        int ans = 0;
        
        // we create another loop, a sliding window that moves backwards to track elements that can be included in AP
        for(int i = index - 1; i >= 0; i--){

            // necessary condition for the element at i to be included in current AP which ends at index
            if(arr[index] - arr[i] == diff)

            // we increment 1 to emulate inclusion of element at i
            ans = max(ans, 1 + solve(arr, diff, i, dp));
        }
        
        // return max ans stored and store it in dp for current index
        return dp[index] = ans;
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        
        // initialize size
        int n = arr.size();

        // return n if only less than 2 element present
        if(n <= 1) return n;

        // store ans
        int ans = 0;

        // create a 1D dp vector because only index is changing on recursion calls
        vector<int> dp(n + 1, -1);

        // loop from 1 to n for changing values of the index
        for(int j = 1; j < n; j++){
            
            // increment by 1 to emulate element at 1 being added to the AP
            ans = max(ans, 1 + solve(arr, difference, j, dp));
        }
        
        // return the max ans stored
        return ans;
    }
};
