class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<int> vis(n, 0);
        queue<int> q;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                provinces++;
                vis[i] = 1;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int j=0; j<n; j++){
                        if(isConnected[node][j] == 1 && !vis[j]){
                            vis[j] = 1;
                            q.push(j);
                        }
                    }
                }
            } 
        }
        return provinces;
    }
};