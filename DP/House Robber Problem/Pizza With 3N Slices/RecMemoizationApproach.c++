class Solution {
public:
    //This solution is same as recursion approach but also incorporates memoization
    int solve(vector<int> &slices, int index, int end, int n, vector<vector<int>> &dp){
        if(n == 0 || index > end) return 0;
        if(dp[index][n] != -1) return dp[index][n];
        int eat = slices[index] + solve(slices, index + 2, end, n - 1, dp);
        int notEaten = solve(slices, index + 1, end, n, dp);
        return dp[index][n] = max(eat, notEaten); 
    }
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        //Two vectors are needed to store the memoization due to 2 function calls
        vector<vector<int>> dp1(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> dp2(n + 1, vector<int>(n + 1, -1));
        int case1 = solve(slices, 0, n - 2, n / 3, dp1);
        int case2 = solve(slices, 1, n - 1, n / 3, dp2);
        return max(case1, case2);
    }
};
