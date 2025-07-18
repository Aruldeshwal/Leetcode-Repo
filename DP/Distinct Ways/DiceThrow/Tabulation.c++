class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // Use long long for dp table to avoid overflow on large results.
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, 0));
        //base case as x == 0 and n == 0 returns 1
        dp[0][0] = 1;
        // we loop for the index of undecided dice
        for(int dice = 1; dice <= n; dice++){
            // loop index of sum
            for(int sum =  1; sum <= x; sum++){
                //initialize answer
                long long ans = 0;
                //loop index of faces
                //we used i <= sum to stop accessing undefined values
                for(int i = 1; i <= m && i <= sum; i++){
                    //we store the previously defined elements into the answer 
                    ans += dp[dice - 1][sum - i];
                }
                //we store the answer of current sum and number of dice inside dp
                dp[dice][sum] = ans;
            }
        }
        //we return the required dp
        return dp[n][x];
    }
};
