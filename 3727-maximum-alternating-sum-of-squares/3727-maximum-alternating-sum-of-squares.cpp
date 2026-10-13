class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();
        for(int i = 0; i<n; i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
    
        long long ans =0;
        if( n%2 == 0){
            for(int i=0 ;i<n/2;i++){
                ans += (nums[n-i-1]*nums[n-i-1])-(nums[i]*nums[i]);
            }
        }
        else{
            for(int i =0; i<n/2;i++){
                ans += (nums[n-i-1]*nums[n-i-1])-(nums[i]*nums[i]);
            }
            ans += (nums[n/2 ]*nums[n/2 ]);
        }
        return ans;
    }
};