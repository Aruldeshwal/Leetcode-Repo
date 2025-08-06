class Solution {
public:
    // Custom comparator to sort meetings by their end times
    static bool cmp(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> v;

        // Combine start and end times into pairs
        for(int i = 0; i < n; i++){
            v.push_back({start[i], end[i]});
        }

        // Sort by end time of the meetings
        sort(v.begin(), v.end(), cmp);

        int count = 1; // At least one meeting is always possible
        int ansEnd = v[0].second; // End time of the first meeting

        // Check if next meeting can be scheduled
        for(int i = 1; i < n; i++){
            if(v[i].first > ansEnd){
                count++;
                ansEnd = v[i].second;
            }
        }

        return count;
    }
};
