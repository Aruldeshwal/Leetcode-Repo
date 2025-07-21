class Solution {
public:
    
    int longestSubsequence(vector<int>& arr, int difference) {
        
        // initialize size
        int n = arr.size();

        // return n if only less than 2 element present
        if(n <= 1) return n;

        // store ans
        int ans = 0;

        // create a 1D dp vector because only index is changing on recursion calls
        vector<int> dp(n + 1, 0);
        
        // loop from 1 to n for changing values of the index
        for(int j = 1; j < n; j++){
            
            int res = 0;
            // we create another loop, a sliding window that moves backwards to track elements that can be included in AP
            for(int i = j - 1; i >= 0; i--){

                // necessary condition for the element at i to be included in current AP which ends at index
                if(arr[j] - arr[i] == difference)

                // we increment 1 to emulate inclusion of element at i
                res = max(res, 1 + dp[i]);
            }
        
            // return max ans stored and store it in dp for current index
            dp[j] = res;
            ans = max(dp[j], ans);
        }
        
        // return the dp element stored at the end
        return 1 + ans;
    }
};
