class Solution {
public:
    
    int longestSubsequence(vector<int>& arr, int difference) {
        
        // initialize size
        int n = arr.size();

        // return n if only less than 2 element present
        if(n <= 1) return n;

        // store ans
        int ans = 0;

        // create an unordered map to store how many elements of the AP exist before current element including it
        unordered_map<int, int> dp(n + 1);
        
        // loop from 0 to n for changing values of the index
        for(int j = 0; j < n; j++){
            
            // previous element of AP
            int temp = arr[j] - difference;

            // store answer of previous element
            int tempAns = 0;

            // if previous AP exists, update tempAns
            if(dp.count(temp)) tempAns = dp[temp];

            // add current element to AP
            dp[arr[j]] = tempAns + 1;

            // store max value in ans between current number of AP elements and previous max
            ans = max(ans, dp[arr[j]]);
        }
        
        // return the dp element stored at the end
        return ans;
    }
};
