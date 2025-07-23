class Solution {
public:
    // Recursive function to find the minimum money needed to guarantee a win
    int solve(int start, int end) {
        // Base case: no cost when start >= end (no numbers left or only one number)
        if(start >= end) return 0;

        int ans = INT_MAX;

        // Try every number i in the range [start, end] as the guess
        for(int i = start; i <= end; i++) {
            // If we guess i, we pay i dollars and the worst case is either left or right subproblem
            int cost = i + max(solve(start, i - 1), solve(i + 1, end));

            // Choose the minimum among all possible guesses
            ans = min(ans, cost);
        }

        return ans;
    }

    // Main function to start the recursion from 1 to n
    int getMoneyAmount(int n) {
        return solve(1, n); 
    }
};
