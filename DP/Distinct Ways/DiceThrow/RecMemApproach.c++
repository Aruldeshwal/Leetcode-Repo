class Solution {
  public:
    //function to solve find the number of ways using recursion 
    long long solve(int &m, int n, int x, vector<vector<long long>> &dp){
        //when x and n reaches 0
        //it implies that this is one of the ways to get the target value so we return 1
        if(x == 0 && n == 0) return 1;
        //if we hit n == 0 it implies no more dices are left but sum is still noy x
        //if x == 0 it implies there are more dices left but we already got the sum so its not a valid answer        
        if(n == 0 || x <= 0) return 0;
        //if dp[n][x] != -1 it implies that it has been computed before, so just return it as it is
        if(dp[n][x] != -1) return dp[n][x];
        //ans is initialized to store all the number of ways of the recursion
        long long ans = 0;
        //i signifies the face of each dice hence it comes out to be between 1 and m inclusive of both
        for(int i = 1; i <= m; i++){
            //n - 1 to show that the face for this dice has been decided which is i 
            //since i is the face subtract it from target sum x
            ans += solve(m, n - 1, x - i, dp);
        }
        //store for current cases and return the ans obtained
        return dp[n][x] = ans;
    }
    int noOfWays(int m, int n, int x) {
        // Use long long for dp table to avoid overflow on large results.
        vector<vector<long long>> dp(n + 1, vector<long long>(x + 1, -1));
        return solve(m, n, x, dp);
    }
};
