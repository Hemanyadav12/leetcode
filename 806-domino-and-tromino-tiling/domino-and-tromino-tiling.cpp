class Solution {
public:
    long long mod = 1000000007;
    int numTilings(int n) {
        if(n == 1 || n == 2) return n;
        // vector<long long> dp(n+1, -1);
        // dp[0] = 1, dp[1] = 1, dp[2] = 2;
        long long x = 1, y = 1, z = 2;  // x for n=0, y for n=1 and z for n=2
        int ans = 0;
        for(int i=3; i<=n; i++){
            //dp[i] = ((2*dp[i-1]) + dp[i-3]) % mod;
            ans = ((2*z) + x) % mod;
            x = y, y = z, z = ans;
        }
        return ans;
    }
};