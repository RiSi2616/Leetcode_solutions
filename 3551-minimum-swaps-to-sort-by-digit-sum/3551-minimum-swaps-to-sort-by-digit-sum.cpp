class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int count =0;

        vector<pair<int,int>> arr;

        for(int i=0; i<n ;i++){
            int a = nums[i];
            int remain=0;
            int sum = 0;
            while(a >0){
                remain = a%10;
                sum += remain;
                a /= 10;
            }
            arr.push_back({sum , nums[i]});
        }
        sort(arr.begin() , arr.end());

        unordered_map<int,int> target;
        for(int i=0; i<n ;i++){
            target[arr[i].second] = i;
        }

        vector<bool> visited (n, false);
        for(int i= 0 ; i<n;i++){
            if(visited[i] || target[nums[i]] == i)continue;

            int cycleSize=0;
            int j=i;


            while(!visited[j]){
                visited[j] =true;
                j = target[nums[j]];
                cycleSize ++;
            }
            count += cycleSize -1;
        }
        return count;
    }
};