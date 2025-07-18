class Solution {
  public:
    //function to solve find the number of ways using recursion 
    long long solve(int &m, int n, int x){
        //when x and n reaches 0
        //it implies that this is one of the ways to get the target value so we return 1
        if(x == 0 && n == 0) return 1;
        //if we hit n == 0 it implies no more dices are left but sum is still not x
        //if x == 0 it implies there are more dices left but we already got the sum so its not a valid answer        
        if(n == 0 || x <= 0) return 0;
        //ans is initialized to store all the number of ways of the recursion
        long long ans = 0;
        //i signifies the face of each dice hence it comes out to be between 1 and m inclusive of both
        for(int i = 1; i <= m; i++){
            //n - 1 to show that the face for this dice has been decided which is i 
            //since i is the face subtract it from target sum x
            ans += solve(m, n - 1, x - i);
        }
        //return the ans obtained
        return ans;
    }
    int noOfWays(int m, int n, int x) {
        return solve(m, n, x, dp);
    }
};
