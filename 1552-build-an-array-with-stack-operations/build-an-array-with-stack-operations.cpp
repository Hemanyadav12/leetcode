class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        vector<string> ans;
        int left=0;
        for(int i=1; i<=target[m-1]; i++){
            ans.push_back("Push");
            if(target[left] != i) ans.push_back("Pop");
            if(target[left] == i) left++;
        }
        return ans;
    }
};