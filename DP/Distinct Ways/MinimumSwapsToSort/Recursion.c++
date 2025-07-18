class Solution {
public:
    //solve function to return the ans
    int solve(vector<int> &nums1, vector<int> &nums2, int curr, int prev){
        //if current index reaches size of the vectors we return 0
        if(curr == nums1.size()) return 0;
        int ans = 0;
        //on the first call, prev is -1, hence we use this if statement to counter it
        if(prev == -1) ans = solve(nums1, nums2, curr + 1, curr);
        //if prev element of either vectors is greater, we swap, to emulate that, we increment the answer
        else if(nums1[curr] < nums1[prev] || nums2[curr] < nums2[prev]) ans = 1 + solve(nums1, nums2, curr + 1, curr);
        //store answer of next index if prev element is already sorted
        else ans = solve(nums1, nums2, curr + 1, curr);
        //return answer
        return ans;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //return answer
        return solve(nums1, nums2, 0, -1);
    }
};
