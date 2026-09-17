class Solution {
public:
    int dfs(vector<vector<int>>& list, vector<bool>& vis, int from){
        auto change = 0;
        vis[from] = true;
        for(auto to : list[from]){
            if(!vis[abs(to)]){
                change += dfs(list, vis, abs(to)) + (to > 0);
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> list(n);
        for(auto &it : connections){
            list[it[0]].push_back(it[1]);
            list[it[1]].push_back(-it[0]);
        }
        vector<bool> vis(n, false);
        return dfs(list, vis, 0);
    }
};