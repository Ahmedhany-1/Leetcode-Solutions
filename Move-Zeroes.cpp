class Solution {
public:
void moveZeroes(vector<int>& nums) {
    int sz = (int) nums.size(), p_zero = 0 , p_nonZero = 0 ;
    while(p_zero < sz && p_nonZero < sz){
        while(p_zero < sz && nums[p_zero] != 0) ++p_zero;
        p_nonZero = max(p_nonZero, p_zero + 1);
        while(p_nonZero < sz && nums[p_nonZero] == 0) ++p_nonZero;
        
        if(p_zero == sz || p_nonZero == sz) break;
        
        swap(nums[p_zero], nums[p_nonZero]);
        ++p_zero;
        ++p_nonZero;
    }
}
/*
nums        = [0, 1, 0, 3, 12]
p_zero      = 0
p_nonZero   = 0

nums        = [1, 0, 0, 3, 12]
p_zero++    → 1
p_nonZero++ → 2

nums        = [1, 3, 0, 0, 12]
p_zero++    → 2
p_nonZero++ → 4

nums        = [1, 3, 12, 0, 0]
p_zero++    → 3
p_nonZero++ → 5

*/
};

// void moveZeroes(vector<int>& nums) {
//     vector<int> ans;
//     int cnt = 0;
//     for(auto &i : nums){
//         if(i) ans.push_back(i);
//         else cnt++;
//     }
//     while(cnt--) ans.push_back(0);
//     nums = ans;
// }