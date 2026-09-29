class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_array(n,1);
        vector<int> right_array(n,1);
        int left = 1, right = 1;
        for(int i=0; i<n; i++){
            left_array[i] *= left;
            left *= nums[i];
        }
        for(int j=n-1; j>=0; j--){
            right_array[j] *= right * left_array[j];
            right *= nums[j];
        }
        return right_array;
    }
};