class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        unordered_map<int, bool> mpp;
        for(int it : target) mpp[it] = true;
        for(int i=1; i<=n; i++){
            if(mpp.empty()) break;
            ans.push_back("Push");
            if(mpp.find(i) == mpp.end()) ans.push_back("Pop");
            mpp.erase(i);
        }
        return ans;
    }
};