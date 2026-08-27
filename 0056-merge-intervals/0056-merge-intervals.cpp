class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int i = 0, j = 1, n = intervals.size();
        int interval = intervals[i][1];
        int intervalNum = 1;
        while(j < n) {
            while(j < n && interval >= intervals[j][0]) {
                interval = max(interval, intervals[j][1]);
                j++;
            } 
            intervals[i][1] = interval;
            i++;
            if(j < n) {
                intervals[i][0] = intervals[j][0];
                interval = intervals[j][1];
                j++;
                intervalNum++;
            }
           
        }
        intervals[i][1] = interval;
        intervals.resize(intervalNum);
        return intervals;
    }
};