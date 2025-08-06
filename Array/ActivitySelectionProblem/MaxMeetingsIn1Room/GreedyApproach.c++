class Solution {
public:
    // Custom comparator: sort meetings by end time
    static bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b){
        return a.first.second < b.first.second;
    }

    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        vector<pair<pair<int, int>, int>> meetings;

        // Store (start, end) and original index (1-based)
        for(int i = 0; i < N; i++){
            meetings.push_back({{S[i], F[i]}, i + 1});
        }

        // Sort by end time
        sort(meetings.begin(), meetings.end(), cmp);

        vector<int> ans;
        int lastEnd = meetings[0].first.second;
        ans.push_back(meetings[0].second); // Always include first meeting

        // Check remaining meetings
        for(int i = 1; i < N; i++){
            if(meetings[i].first.first > lastEnd){
                ans.push_back(meetings[i].second);
                lastEnd = meetings[i].first.second;
            }
        }

        // Sort answer if needed
        sort(ans.begin(), ans.end());
        return ans;
    }
};
