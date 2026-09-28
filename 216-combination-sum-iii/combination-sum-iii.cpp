class Solution {
public:
    void combSum(vector<vector<int>>& ans, vector<int>& comb, int k, int n, int sum, int num, int idx){
        if(sum == n && num == k){
            ans.push_back(comb);
            return;
        }
        if(idx > 9) return;
        comb.push_back(idx);
        combSum(ans, comb, k, n, sum+idx, num+1, idx+1);
        comb.pop_back();
        combSum(ans, comb, k, n, sum, num, idx+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        combSum(ans, comb, k, n, 0, 0, 1);
        return ans;
    }
};