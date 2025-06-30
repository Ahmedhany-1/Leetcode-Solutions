class Solution {
    bool can(long long x , int target){
        return (x * (x + 1) / 2) <= target;
    }
public:
    int arrangeCoins(int n) {
        int l = 0, r = n, ans = -1 , mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(can(mid, n)){
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        }
        return ans;
    }
};