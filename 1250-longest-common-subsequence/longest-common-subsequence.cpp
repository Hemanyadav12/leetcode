class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> ans(m+1, vector<int>(n+1, 0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text2[i-1] == text1[j-1]){
                    ans[i][j] = ans[i-1][j-1]+1;
                }else{
                    ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
                }
            }
        }
        return ans[m][n];
    }
};