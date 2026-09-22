class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        int n = spells.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            long long temp = (success + spells[i] - 1)/spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), temp);
            ans[i] = potions.end() - it;
        }
        return ans;
    }
};