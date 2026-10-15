static const int _ = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0}); // coordinates, steps
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};

        while(!q.empty()){
            auto node = q.front();
            int x = node[0];
            int y = node[1];
            int step = node[2];
            q.pop();
            if((x==0 || x==m-1 || y==0 || y==n-1) && (x!=entrance[0] || y!=entrance[1])) return step;
            for(int i=0; i<4; i++){
                int nx = x + dr[i];
                int ny = y + dc[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && maze[nx][ny]=='.' && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({nx,ny,step+1});
                }
            }
        }
        return -1;
    }
};