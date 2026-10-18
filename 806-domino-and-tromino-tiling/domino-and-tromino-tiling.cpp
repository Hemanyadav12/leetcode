class Solution {
public:
    long long mod = 1000000007;
    long long func(int n, vector<int>& dp){
        if(n == 1 || n == 2) return n;
        if(dp[n] != 0) return dp[n];
        return dp[n] = ((2*func(n-1,dp)) + func(n-3,dp)) % mod;
    }
    int numTilings(int n) {
        if(n == 1 || n == 2) return n;
        vector<int> dp(n+1, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        func(n,dp);
        return dp[n];
    }
};