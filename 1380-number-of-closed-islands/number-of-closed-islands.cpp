class Solution {
public:
    void func(vector<vector<int>>& grid, int row, int col, int &flag){
        if(row >= grid.size() || row < 0 || col >= grid[0].size() || col < 0) return;
        if((row == grid.size()-1 || row == 0 || col == grid[0].size()-1 || col == 0) && grid[row][col] == 0){
            flag = 1;
            return;
        }
        if(grid[row][col] != 0) return;
        grid[row][col] = 2; //visited land
        func(grid, row+1, col, flag);
        func(grid, row-1, col, flag);
        func(grid, row, col+1, flag);
        func(grid, row, col-1, flag);
    }
    int closedIsland(vector<vector<int>>& grid) {
       int count = 0;
       for(int i=1; i<grid.size()-1; i++){
            for(int j=1; j<grid[0].size()-1; j++){
                if(grid[i][j] == 0){
                    int flag = 0;
                    func(grid, i , j, flag);
                    if(flag != 1) count++;
                }
            }
        } 
        return count;
    }
};