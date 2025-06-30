class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum_so_far = 0 , cur_sum = 0;
        for(auto it : nums) sum_so_far += it;
        int ans = 0;
        for(int i = 0 ; i < nums.size() - 1 ; ++i){
            cur_sum += nums[i];
            if(cur_sum >= sum_so_far - cur_sum) ans++;
        }
        return ans;
    }
};