class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;
        int max_points = 1;
        for(int i=0; i<n; i++){
            unordered_map<string, int> slope;
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<n; j++){
                int dx = points[j][0] - x1;
                int dy = points[j][1] - y1;
                int g = gcd(dx,dy);
                dx /= g;
                dy /= g;
                if(dx < 0){
                    dx = -dx;
                    dy = -dy;
                }else if(dx == 0){
                    dy = abs(dy);
                }
                string key = to_string(dy) + "/" + to_string(dx);
                slope[key]++;
            }
            for(auto it : slope){
                max_points = max(max_points, it.second+1);
            }
        }
        return max_points;
    }
};