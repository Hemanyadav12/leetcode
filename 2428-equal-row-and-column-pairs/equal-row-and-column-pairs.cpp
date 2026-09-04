class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int count = 0;
        vector<vector<int>> transpose(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                transpose[j][i] = grid[i][j];
            }
        }
        map<vector<int>,int> trans_count;
        for(int i=0; i<n; i++) trans_count[transpose[i]]++;

        for(int i=0; i<n; i++){
            if(trans_count.count(grid[i])) count += trans_count[grid[i]];
        }
        return count;
    }
};