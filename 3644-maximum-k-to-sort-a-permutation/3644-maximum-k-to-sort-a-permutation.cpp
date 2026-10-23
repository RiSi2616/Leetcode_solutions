class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int ans =-1;
        bool sorted = true;

        for(int i = 0; i<n ;i++){
            if(nums[i]!=i){
                sorted = false;
                ans = (ans == -1) ? nums[i] : (ans & nums[i]);
            }
        }
        return sorted ? 0 : ans;
    }
};