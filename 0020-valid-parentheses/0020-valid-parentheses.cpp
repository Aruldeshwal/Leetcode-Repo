class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch : s) {
            if(ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
                continue;
            }
            else if(!st.empty()) {
                char ele = st.top();
                st.pop();
                if((ele == '(' && ch != ')') || (ele == '{' && ch != '}') || (ele == '[' && ch != ']')) return false;
            }
            else if(st.empty() && (ch == ')' || ch == ']' || ch == '}')) return false;
        }
        if(!st.empty()) return false;
        return true;
    }
};