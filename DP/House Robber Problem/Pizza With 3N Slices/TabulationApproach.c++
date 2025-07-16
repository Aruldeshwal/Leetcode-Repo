class Solution {
public:
    //First we analyze our rec + memoization approach
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp1(n + 2, vector<int>(n + 2, 0));
        vector<vector<int>> dp2(n + 2, vector<int>(n + 2, 0));
        //we use i and j to emulate the working of index and n respectively
        //index starts from 0 for case 1 and goes all the way up to n-2 in recursion, since its a bottom up approach, we do the reverse in tabulation
        for(int i = n - 2; i >= 0; i--){
        //n starts from n/3 and goes to zero for first case in recursion, so, it goes opposite in tabulation
            for(int j = 1; j <= n/3; j++){
                //the logic is same, instead of using recursion, we store the solution in dp1 and then get the final answer at the last most part of loop, which is index = 0 and n = n / 3
                int eat = slices[i] + dp1[i + 2][j - 1];
                int notEaten = dp1[i + 1][j];
                dp1[i][j] = max(eat, notEaten); 
            }
        }
        int case1 = dp1[0][n / 3];
        //Case 2 index starts from 1 to n - 1 in rec, hence, it goes from n - 1 to 1 for tabulation
        for(int i = n - 1; i >= 1; i--){
            //same as case 1
            for(int j = 1; j <= n/3; j++){
                //we use dp2 to store answers
                int eat = slices[i] + dp2[i + 2][j - 1];
                int notEaten = dp2[i + 1][j];
                dp2[i][j] = max(eat, notEaten); 
            }
        }
        int case2 = dp2[1][n / 3];
        //return max of the 2 cases
        return max(case1, case2);

    }
};
