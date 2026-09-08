class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        stack<pair<int, int>> st;
        int n = position.size();
        for(int i = 0; i < n; i++) {
            st.push({position[i], speed[i]});
        }
        int count = 0;
        while(!st.empty()) {
            pair<int, int> element = st.top();
            st.pop();
            if(st.empty()) {
                count++;
                break;
            }
            while(!st.empty() && (element.first - st.top().first <= distance || element.second < st.top().second)) {
                element.first = st.top().first;
                st.pop();
            } 
            count++;
        }
        return count;
    }
};