class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        // base case
        dp[0] = dp[1] = 1;

        // represents number of nodes
        for(int i = 2; i <= n; i++){
            // store ans by summation after solving for each node from 1 to n
            int ans = 0;

            // represents root node from 1 to i 
            for(int j = 1; j <= i; j++)
                // numtrees(i - 1) is called to emulate everything at the left side of current node
                // for example- if 2 is current node, 1 is in the left and 3 is on the right 
                // if current element is i, there are i - 1 nodes at the left side of the tree
                // if current element is i, the window becomes i + 1 to n, which is n - i nodes
                ans += dp[j - 1] * dp[i - j];

            // return the answer obtained for current recursion stack
            dp[i] = ans;
        }

        // return dp element stored at the upper limit
        return dp[n];
    }
};
