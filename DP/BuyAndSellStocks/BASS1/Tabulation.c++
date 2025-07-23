class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, j=1, profit=0;
        
        // if prices vector has only 0 or 1 element, return 0 
        if(prices.size()<2) return profit;
        
        while(j<prices.size()){

            // if prices of i is greater than prices of j
            // update i as j (i is the index of smallest element)
            if(prices[i]>prices[j]){
                i=j;
            }

            // if new lowest price is not found 
            // find if current element - lowest price till now is greater than previous greatest difference
            else{
                profit=max(profit, prices[j]-prices[i]);
            }

            // increment j
            j++;
        }
        return profit;
    }
};
