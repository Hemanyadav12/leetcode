class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        queue<int> q;
        vis[0] = 1;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i : rooms[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        for(int i=0; i<vis.size(); i++){
            if(vis[i] == 0) return false;
        }
        return true;
    }
};