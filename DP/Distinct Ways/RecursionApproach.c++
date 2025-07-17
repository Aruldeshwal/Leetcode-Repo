class Solution {
  public:
    //function to solve find the number of ways using recursion 
    int solve(int &m, int n, int &x, int sum){
        //when sum is equal to target value and n reaches 0
        //it implies that this is one of the ways to get the target value so we return 1
        if(sum == x && n == 0) return 1;
        //if we hit n == 0 it implies no more dices are left but sum is still noy x
        //if sum is x it implies there are more dices left but we already got the sum so its not a valid anseer
        if(n == 0 || sum == x) return 0;
        //ans is initialized to store all the number of ways of the recursion
        int ans = 0;
        //i signifies the face of each dice hence it comes out to be between 1 and m inclusive of both
        for(int i = 1; i <= m; i++){
            //n - 1 to show that the face for this dice has been decided which is i 
            //since i is the face we add it to sum
            ans += solve(m, n - 1, x, sum + i);
        }
        //return the ans obtained
        return ans;
    }
    int noOfWays(int m, int n, int x) {
        return solve(m, n, x, 0);
    }
};
