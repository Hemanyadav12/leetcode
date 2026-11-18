class Solution {
public:
    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<int>>& ocean, int prevHeight){
        int m = heights.size(), n = heights[0].size();
        if(row < 0 || col < 0 || row >= m || col >= n || ocean[row][col] == 1 || heights[row][col] < prevHeight) return;
        ocean[row][col] = 1;
        dfs(heights, row-1, col, ocean, heights[row][col]);
        dfs(heights, row+1, col, ocean, heights[row][col]);
        dfs(heights, row, col+1, ocean, heights[row][col]);
        dfs(heights, row, col-1, ocean, heights[row][col]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n,0));
        
        for(int j=0; j<n; j++){
            dfs(heights, 0, j, pacific, heights[0][j]);
            dfs(heights, m-1, j, atlantic, heights[m-1][j]);
        }

        for(int i=0; i<m; i++){
            dfs(heights, i, 0, pacific, heights[i][0]);
            dfs(heights, i, n-1, atlantic, heights[i][n-1]);
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};