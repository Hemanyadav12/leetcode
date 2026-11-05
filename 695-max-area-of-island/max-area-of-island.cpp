class Solution {
public:
    void cal_area(vector<vector<int>>& grid, int row, int col, int& area){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if(grid[row][col] == 0) return;
        grid[row][col] = 0; // mark visited
        area += 1;
        cal_area(grid, row+1, col, area);
        cal_area(grid, row-1, col, area);
        cal_area(grid, row, col+1, area);
        cal_area(grid, row, col-1, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = INT_MIN;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    cal_area(grid, i, j, area);
                    max_area = max(area, max_area);
                }
            }
        }
        if(max_area == INT_MIN) return 0;
        return max_area;
    }
};