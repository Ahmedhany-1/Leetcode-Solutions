class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
        int mini = nums[0];
        int maxi = nums[0];

        for(int i = 1; i<n;i++)
        {
            if(mini < nums[i] || maxi > nums[i])
            {
                mini = mini < nums[i] ? nums[i] : mini;
                maxi = maxi > nums[i] ? nums[i] : maxi;
                continue;
            }

            for(int j = 0; j<i; j++)
            {
                if(nums[j] == nums[i])
                {
                    return true;
                }
            }
        }
        return false;
    }
};