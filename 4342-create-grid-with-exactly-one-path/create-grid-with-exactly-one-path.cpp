class Solution {
public:
    bool dfs(vector<string>& path, int row, int col, int m, int n){
        if(row < 0 || row >= m || col < 0 || col >= n) return false;
        path[row][col] = '.';
        if(row == m-1 && col == n-1) return true;
        if(dfs(path, row, col+1, m, n)) return true;
        if(dfs(path, row+1, col, m, n)) return true;
        return false;
    }
    vector<string> createGrid(int m, int n) {
        vector<string> path(m, string(n, '#'));
        dfs(path, 0, 0, m, n);
        return path;
    }
};