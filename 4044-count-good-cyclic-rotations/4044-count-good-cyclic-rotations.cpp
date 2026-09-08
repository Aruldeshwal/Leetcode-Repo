class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int j = n / 2;
        long long firstSum = 0;
        long long lastSum = 0;
        while(i < n / 2 && j < n) {
            firstSum += nums[i++];
            lastSum += nums[j++];
        }
        int count = 0;
        if(firstSum < lastSum) count++;
        i--;
        j--;
        int nI = i + 1;
        int nJ = 0;
        while(nI != i && nJ != j) {
            firstSum = firstSum + nums[nI] - nums[nJ];
            lastSum = lastSum + nums[nJ] - nums[nI];
            if(firstSum < lastSum) count++;
            nI++;
            nJ++;
            if(nI == n) nI = 0;
        }
        return count;
    }
};