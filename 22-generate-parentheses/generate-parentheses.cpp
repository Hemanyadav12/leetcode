class Solution {
public:
    void comb(vector<string>& ans, int n, int open, int close, string s){
        if(s.size() == 2*n){
            ans.push_back(s);
            s = "";
            return;
        }
        if(open < n) comb(ans, n, open+1, close, s+'(');
        if(close < open) comb(ans, n, open, close+1, s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        comb(ans, n, 0, 0, s);
        return ans;
    }
};