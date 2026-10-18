class Solution {
public:
    long long mod = 1000000007;
    int numTilings(int n) {
        if(n == 1 || n == 2) return n;
        long long x = 1, y = 1, z = 2;  // x for n=0, y for n=1 and z for n=2
        int ans = 0;
        for(int i=3; i<=n; i++){
            ans = ((2*z) + x) % mod;
            x = y, y = z, z = ans;
        }
        return ans;
    }
};