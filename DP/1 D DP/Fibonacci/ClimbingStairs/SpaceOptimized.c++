class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return n;
        int prev = 1;
        int curr = 2;
        for(int i = 3; i <= n; i++) {
            int temp = curr;
            curr = curr + prev;
            prev = temp;
        }
        return curr;
    }
};
