class Solution {
    bool valid(vector<int>& nums, int threshold, int divisor){
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            ans += (nums[i] + divisor - 1) / divisor;
        }
        return ans <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6 + 5;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(valid(nums, threshold, mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};