class Solution {
public:
    //solve function to return the ans
    int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp){
        //if current index reaches size of the vectors we return 0
        if(index == nums1.size()) return 0;
        //return if element in dp has been changed
        if(dp[index][swapped] != -1) return dp[index][swapped];
        //initialize answer as int max to store minimum answer
        int ans = INT_MAX;
        //prev element of first vector
        int prev1 = nums1[index - 1];
        //prev element of second vector
        int prev2 = nums2[index - 1];
        //if previous element was swapped
        if(swapped) swap(prev1, prev2);
        //if curr element of both vectors are greater than prev elements then we dont swap
        if(nums1[index] > prev1 && nums2[index] > prev2) ans = solve(nums1, nums2, index + 1, false, dp);
        //if curr element of vector 1 is greater than previous of vector 2 and vice verse, we can swap
        if(nums1[index] > prev2 && nums2[index] > prev1)
            //we take minimum in case this index executes for both swap and noswap 
            ans = min(ans, solve(nums1, 1 + nums2, index + 1, true, dp));
        //store in dp and return answer
        return dp[index][swapped] = ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //insert -1 in beginning of both arrays to counter edge case
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        //it shows if prev index is swapped or not
        bool swapped = 0;
        //we create a 2D dp to emulate 2 arguments changing for recursion calls
        vector<vector<int>> dp(nums1.size() + 1, vector<int> (2, -1));
        //we start from index 1 as prev element to 1 is -1
        return solve(nums1, nums2, 1, swapped, dp);
    }
};
