class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int maxWater = 0;
        while(i < j) {
            int b = j - i;
            int h = min(height[i], height[j]);
            maxWater = max(maxWater, h * b);
            if(height[j] > height[i]) i++;
            else j--;
        }
        return maxWater;
    }
};