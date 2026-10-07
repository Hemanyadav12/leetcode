class Solution {
public:
    bool check_valid(string s1){
        int balance = 0;
        for (char c : s1) {
            if (c == '(') balance++;
            else if (c == ')') balance--;
            if (balance < 0) return false; 
        }
        return balance == 0;
    }
    void comb(string& s, string& curr, int idx, int close, int open, unordered_set<string>& st){
        if(idx == s.size()){
            if(close == 0 && open == 0 && check_valid(curr)) st.insert(curr);
            return;
        }
        char c = s[idx];
        if(s[idx] == ')' && close > 0) comb(s, curr, idx+1, close-1, open, st);
        if(s[idx] == '(' && open > 0) comb(s, curr, idx+1, close, open-1, st);
        curr.push_back(c);
        comb(s, curr, idx+1, close, open, st);
        curr.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        int close = 0, open = 0;
        // for(int i=0; i<s.size(); i++){
        //     if(s[i] == '(') open++;
        //     else if (s[i] == ')') close++;
        // }
        // int remove = abs(close - open);
        for(char c : s){
            if(c == '(') open++;
            else if(c == ')'){
                if(open > 0) open--;
                else close++;
            }
        }
        unordered_set<string> st;
        string curr = "";
        comb(s, curr, 0, close, open, st);
        return vector<string>(st.begin(), st.end());
    }
};