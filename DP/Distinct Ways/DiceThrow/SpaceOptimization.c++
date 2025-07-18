class Solution {
  public:
    int noOfWays(int m, int n, int x) {
        // Use long long for dp table to avoid overflow on large results.
        // Make a previous and current vector to optimize space
        vector<long long> prev(x + 1, 0);
        vector<long long> curr(x + 1, 0);
        //base case as x == 0 and n == 0 returns 1
        //dice starts from 1 which is the current index
        //so previous index is 0
        prev[0] = 1;
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
                    ans += prev[sum - i];
                }
                //we store the answer of current sum and number of dice inside dp
                curr[sum] = ans;
            }
            //we convert prev into curr to emulate the increment in number of dice
            prev = curr;
        }
        //we return the required element
        return prev[x];
    }
};
