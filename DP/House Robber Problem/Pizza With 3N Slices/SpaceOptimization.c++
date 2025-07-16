class Solution {
public:

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        //to optimize space, we analyze the dependency of dp1[i][j] and dp2[i][j]
        //dp1[i][j] depends on dp1[i + 1][j] and dp1[i + 2][j - 1]
        //similarly, dp2[i][j] depends on dp2[i + 1][j] and dp1[i + 2][j - 1]
        //we can ascertain that dp[i][j] depends on dp[i + 1][j] and dp[i + 2][j - 1]
        //if we take dp[i] as prev, we get dp[i + 1] as curr and dp[i + 2] as next
        //This converts the O(n^2) space into O(n)
        vector<int> prev1(n + 2, 0);
        vector<int> curr1(n + 2, 0);
        vector<int> next1(n + 2, 0);
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = 1; j <= n/3; j++){
                int eat = slices[i] + next1[j - 1];
                int notEaten = curr1[j];
                prev1[j] = max(eat, notEaten); 
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[n / 3];

        vector<int> prev2(n + 2, 0);
        vector<int> curr2(n + 2, 0);
        vector<int> next2(n + 2, 0);
        for(int i = n - 1; i >= 1; i--){
            for(int j = 1; j <= n/3; j++){

                int eat = slices[i] + next2[j - 1];
                int notEaten = curr2[j];
                prev2[j] = max(eat, notEaten); 
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[n / 3];

        return max(case1, case2);

    }

};
