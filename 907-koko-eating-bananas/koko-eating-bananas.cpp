class Solution {
public:
    long long cal(vector<int>& piles, int k){
        long long cal1 = 0;
        for(int i=0; i<piles.size(); i++){
            cal1 += (piles[i] + k -1)/k;
        }
        return cal1;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if(h < n) return -1;
        sort(piles.begin(), piles.end());
        int min_speed = 1;
        int max_speed = piles[n-1];
        int ans = piles[n-1];
        while(min_speed <= max_speed){
            int mid = min_speed + (max_speed - min_speed)/2;
            long long num = cal(piles, mid);
            if(num <= h){
                ans = min(mid, ans);
                max_speed = mid-1;
            }else{
                min_speed = mid+1;
            }
        }
        return ans;
    }
};