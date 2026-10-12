class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> mp;
        for(int i=0 ; i<n ;i++){
            mp.insert(nums[i]);
        }
        vector<int> ans;

        for(int i=0; i<n ;i++){
            if(mp.find(i+1) != NULL){
                continue;
            }
            else{
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};