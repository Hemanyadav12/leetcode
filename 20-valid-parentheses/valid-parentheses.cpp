class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1) return false;
        int open = 0, close = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') open++;
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']') close++;
        }
        if(open != close) return false;
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
            else if(s[i] == ')' && !st.empty() && st.top() == '(') st.pop();
            else if(s[i] == '}' && !st.empty() && st.top() == '{') st.pop();
            else if(s[i] == ']' && !st.empty() && st.top() == '[') st.pop();
        }
        if(st.empty()) return true;
        return false;
    }
};