class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b = prices[0];
        int s = 0;
        int ans = 0;
        for (int p : prices) {
            if(p > s) {
                s = p;
            }
            else if(p < b) {
                b = p;
                s = p;
            }
            ans = max(ans, s - b);
        }
        return ans;
    }
};