class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh_orange = 0, steps = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh_orange++;
            }
        }
        if(fresh_orange == 0) return 0;
        if(q.empty()) return -1;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto temp = q.front();
                int x = temp.first;
                int y = temp.second;
                q.pop();
                for(auto [dx,dy] : dir){
                    int r = x + dx;
                    int c = y + dy;
                    if(r >= 0 && r < m && c >=0 && c < n && grid[r][c] == 1){
                        grid[r][c] = 2;
                        fresh_orange--;
                        q.push({r,c});
                    }
                }
            }
            steps++;
        }
        if(fresh_orange == 0) return steps-1;
        return -1;
    }
};