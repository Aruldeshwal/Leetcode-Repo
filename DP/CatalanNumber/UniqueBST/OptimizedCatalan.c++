class Solution {
public:
    int numTrees(int n) {
        // store result
        long long res = 1;

        // represents terms starting from 0 all the way to n - 1
        for(int i = 0; i < n; i++){

            // catalan number formula is 1 by n + 1 into 2 n factorial upon n factorial squared
            // 2 n factorial upon n factorial can be simplified to (2n)⋅(2n−1)⋅…⋅(n+1)
            // now, 2 * n - 0 = 2n
            // similarly 2 * n - 1 = 2n - 1
            // thus since, i starts from 0 to n, 2 * n - i represents (2n)⋅(2n−1)⋅…⋅(n+1)
            // i + 1 represents the additional n factorial left in denominator
            res = res * (2 * n  - i)/ (i + 1);
        }

        // return res divided by n + 1 for the last pass since our loop stopped at < n
        return res / (n + 1);
    }
};
