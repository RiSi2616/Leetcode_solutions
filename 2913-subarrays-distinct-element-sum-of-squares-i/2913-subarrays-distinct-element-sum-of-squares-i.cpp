class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> s;
        int square = 0;
        for(int i= 0 ; i<n ;i++){
            int diff =0;
            for(int j=i ; j<n ; j++){
                int k=i;
                while(k<=j){
                    s.insert(nums[k]);
                    k++;
                }
                diff = s.size();
                square += diff * diff;
                s.clear();
            }
            
        }
        return square;
    }
};