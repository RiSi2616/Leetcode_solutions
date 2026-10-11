class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans =0;
        int n= columnTitle.length();
        if(n == 1) return (columnTitle[0] -  64);
        
        int i=0;
        while(i<n){
            ans = ans* 26 + (columnTitle[i]-64);
            i++;
        }
        return ans;
    }
};