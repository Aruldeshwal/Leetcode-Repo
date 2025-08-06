class Solution {
public:
    // Custom comparator to sort intervals based on the starting point
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort the intervals based on their starting times
        sort(intervals.begin(), intervals.end(), cmp);

        vector<vector<int>> ans; // This will store the final merged intervals

        // Step 2: Initialize with the first interval
        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1]; 

        // Step 3: Iterate through the remaining intervals
        for(int i = 1; i < intervals.size(); i++) {
            // Check if current interval overlaps with the previous one
            if(prevEnd >= intervals[i][0]) {
                // If yes, merge by updating the end to the max of both ends
                prevEnd = max(prevEnd, intervals[i][1]);
            } else {
                // No overlap, so push the previous interval to answer
                ans.push_back({prevStart, prevEnd});

                // And update prevStart and prevEnd to the current interval
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];  
            }
        } 

        // Step 4: Push the last interval that was being tracked
        ans.push_back({prevStart, prevEnd});

        // Step 5: Return the merged list
        return ans;
    }
};
