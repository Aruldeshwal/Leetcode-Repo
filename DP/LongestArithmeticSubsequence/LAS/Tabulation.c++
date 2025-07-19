class Solution {
public:

    int lengthOfLongestAP(vector<int>& arr) {
        
        int n = arr.size();
        
        // if array only contains less than 3 elements then all elements are part of the AP
        if(n <= 2) return n;
        
        // store the maximum value obtained after all the passes inside ans
        int ans = 0;
        
        // initialize 2D dp to emulate changing of two arguments in recursion
        vector<vector<int>> dp(n + 1, vector<int> (arr[n - 1] - arr[0] + 1, -1));
        
        // create a double-nested loop
        for(int i = 1; i < n; i++){
            // The inner loop selects the second potential term, ensuring it comes after the first.
            for(int j = 0; j < i; j++){
                // includes j element so count is initialized as 1
                int count = 1;
                
                int diff = arr[i] - arr[j];
                
                // if dp element has been altered count is altered
                if(dp[j][diff] != -1){
                    // count will be equal to previously established sub problem
                    count = dp[j][diff];
                }
                
                // store 1 + count as dp element for current index i
                // add 1 to count to include i element
                dp[i][diff] = 1 + count;
                
                // store maximum element as answer
                ans = max(ans, dp[i][diff]);
            }
        }
        // return the max length of AP that can be formed
        return ans;
    }
};
