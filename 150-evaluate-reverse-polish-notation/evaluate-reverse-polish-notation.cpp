class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens){
            if(it == "+" || it == "-" || it == "*" || it == "/"){
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                int result = 0;
                if(it == "+") result = x + y;
                else if(it == "-") result = x - y;
                else if(it == "*") result = x * y;
                else if(it == "/") result = x / y;
                st.push(result);
            }else st.push(stoi(it));
        }
        return st.top();
    }
};