class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //insert -1 in beginning of both arrays to counter edge case
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

        //create two DPs that store element based on value of swapped
        vector<int> next(2, 0);
        vector<int> curr(2, 0);
        
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
                if(nums1[index] > prev1 && nums2[index] > prev2) ans = next[false];
                //if curr element of vector 1 is greater than previous of vector 2 and vice verse, we can swap
                if(nums1[index] > prev2 && nums2[index] > prev1)
                //we take minimum in case this index executes for both swap and noswap 
                ans = min(ans, 1 + next[true]);
                //store in current vector 
                curr[swapped] = ans;
            }
            next = curr;
        }
        //return lower limits of the two loops
        return next[0];
    }
};
