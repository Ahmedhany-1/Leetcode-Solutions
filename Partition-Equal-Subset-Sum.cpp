class Solution {
    vector<vector<int>> mem;
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &i : nums)
            sum += i;
        
        if(sum & 1) return 0;

        mem.resize(nums.size(), vector<int>(sum, -1));
        return solve(0, 0, nums, sum);
    }

    bool solve(int i, int sum_so_far, vector<int>& nums, int total_sum){
        if(i == nums.size()) {
            return sum_so_far == total_sum - sum_so_far;
        }

        auto &ret = mem[i][sum_so_far];
        if(ret != -1) return ret;

        return ret = solve(i + 1, sum_so_far + nums[i], nums, total_sum) ||
        solve(i + 1, sum_so_far, nums, total_sum);
    }
};