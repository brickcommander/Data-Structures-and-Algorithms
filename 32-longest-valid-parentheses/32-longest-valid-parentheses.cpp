class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == ')') {
                if(!st.empty() && s[st.top()] == '(') st.pop();
                else st.push(i);
            } else {
                st.push(i);
            }
        }
        
        int longest = (st.empty() ? s.size() : s.size()-st.top()-1);
        int a = s.size(), b = 0;
        while(!st.empty()) {
            b = st.top(); st.pop();
            longest = max(longest, a-b-1);
            a = b;
        }
        longest = max(longest, a);
        
        return longest;        
    }
};