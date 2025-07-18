class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //insert -1 in beginning of both arrays to counter edge case
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

        //we create a 2D dp to emulate 2 arguments changing for recursion calls
        vector<vector<int>> dp(nums1.size() + 1, vector<int> (2, 0));
        
        for(int index = n - 1; index >= 1; index--){
            for(int swapped = 1; swapped >= 0; swapped--){
                //initialize answer as int max to store minimum answer
                int ans = INT_MAX;
                //prev element of first vector
                int prev1 = nums1[index - 1];
                //prev element of second vector
                int prev2 = nums2[index - 1];
                //if previous element was swapped
                if(swapped) swap(prev1, prev2);
                //if curr element of both vectors are greater than prev elements then we dont swap
                if(nums1[index] > prev1 && nums2[index] > prev2) ans = dp[index + 1][false];
                //if curr element of vector 1 is greater than previous of vector 2 and vice verse, we can swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                //we take minimum in case this index executes for both swap and noswap 
                ans = min(ans, 1 + dp[index + 1][true]);
                //store in dp 
                dp[index][swapped] = ans;
            }
        }
        //return lower limits of the two loops
        return dp[1][0];
    }
};
