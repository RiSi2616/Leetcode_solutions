class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1)return true;
        

       
        long long product=1;
        while(product <= n){
            product *= 4;
            if(product == n)return true;
            else if(product > n) return false;
        }
        return false;
    }
};