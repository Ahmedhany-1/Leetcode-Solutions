class Solution {
   int dp[200][10001];
public:
    bool solve(int idx , int target , vector<int>& nums){
        if(idx == nums.size() || target < 0) return false;
        if(target == 0) return true;

       if(dp[idx][target] != -1) return dp[idx][target];

        bool op1 = solve(idx + 1 , target , nums);
        bool op2 = op2 = solve(idx + 1 , target - nums[idx] , nums);

       return dp[idx][target] = op1 || op2;
    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        int total_sum = accumulate(nums.begin() , nums.end() , 0);
        if(total_sum & 1) return false;
        return solve(0 , total_sum / 2 , nums);
    }   
};