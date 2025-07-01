class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = (int)nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i < n; ++i){
            for(int j = i + 1 ; j < n; ++j){
                int l = j + 1, r = n;
                while(l < r){
                    int mid = l + (r - l) / 2;
                    if(nums[mid] < nums[i] + nums[j]) l = mid + 1;
                    else r = mid;
                }
                ans += r - j - 1;
            }
        }
        return ans;
    }
};