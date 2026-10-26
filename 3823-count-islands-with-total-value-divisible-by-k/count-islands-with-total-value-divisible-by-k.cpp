class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, long long &cell_sum){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if(grid[row][col] == 0) return;
        cell_sum += grid[row][col];
        grid[row][col] = 0; // mark as visited
        dfs(grid, row+1, col, cell_sum);
        dfs(grid, row-1, col, cell_sum);
        dfs(grid, row, col+1, cell_sum);
        dfs(grid, row, col-1, cell_sum); 
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int island = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0){
                    long long cell_sum = 0;
                    dfs(grid, i, j, cell_sum);
                    if(cell_sum % k == 0) island++;
                }
            }
        }
        return island;
    }
};