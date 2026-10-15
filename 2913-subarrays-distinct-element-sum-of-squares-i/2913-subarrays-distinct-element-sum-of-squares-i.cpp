class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int square = 0;
        for(int i= 0 ; i<n ;i++){
            unordered_set<int> s;
            int diff =0;
            for(int j=i ; j<n ; j++){
                s.insert(nums[j]);
                diff = s.size();
                square += diff * diff;
            }
            
        }
        return square;
    }
};