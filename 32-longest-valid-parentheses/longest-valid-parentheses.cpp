class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        stack<int> st;
        int ans = 0;
        st.push(-1);
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') st.push(i);
            if(s[i] == ')'){
                st.pop();
                if(!st.empty()){
                    int len = i - st.top();
                    ans = max(ans, len);
                }
                else if(st.empty()) st.push(i);
            }
        }
        return ans;
    }
};