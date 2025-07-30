class Solution {
public:
    // Comparator function to sort activities by finish time (ascending)
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }

    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<pair<int, int>> v;
        int n = start.size();

        // Pair up start and finish times for each activity
        for(int i = 0; i < n; i++) {
            v.push_back({start[i], finish[i]});
        }

        // Sort all activities by their finish time
        sort(v.begin(), v.end(), cmp);

        // First activity is always selected
        int prev = v[0].second;
        int count = 1;

        // Loop through the rest of the activities
        for(int i = 1; i < n; i++) {
            // If current activity starts after previous selected one ends
            if(prev < v[i].first) {
                count++;                // Select this activity
                prev = v[i].second;     // Update end time of last selected activity
            }
        }

        return count; // Total non-overlapping activities that can be done
    }
};
