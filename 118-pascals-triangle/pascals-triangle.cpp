class Solution {
public:
    void func(vector<vector<int>>& ans, int numRows, vector<int>& comb, int idx){
        if(idx == numRows) return;
        vector<int> comb2;
        comb2.push_back(comb[0]);
        for(int i=0; i<comb.size()-1; i++){
            comb2.push_back(comb[i]+comb[i+1]);
        }
        comb2.push_back(comb[comb.size()-1]);
        ans.push_back(comb2);
        func(ans, numRows, comb2, idx+1);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> comb;
        ans.push_back({1});
        if(numRows == 1) return ans;
        ans.push_back({1,1});
        if(numRows == 2) return ans;
        comb.push_back(1);
        comb.push_back(1);
        func(ans, numRows, comb, 2);
        return ans;
    }
};