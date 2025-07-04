class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last = upper_bound(nums.begin(), nums.end(), target);

        if (first == nums.end() || *first != target)
            return {-1, -1};

        int idx_1 = first - nums.begin();
        int idx_2 = last - nums.begin() - 1;
        return {idx_1, idx_2};
    }
};
