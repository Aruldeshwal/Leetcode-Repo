class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int prev = intervals[0][1];
        for(int i = 1; i < n; i++) {
            if(prev > intervals[i][0]) {
                res++;
            } else {
                prev = intervals[i][1];
            }
        }
        return res;
    }
};