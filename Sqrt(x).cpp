class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        int l = 1, r = x / 2;
        while(l < r){
            int mid = l + (r - l + 1) / 2;
            if(1ll * mid * mid <= x) 
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};