class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> ans;
        int cnt = 0;
        for(auto &i : nums){
            if(i) ans.push_back(i);
            else cnt++;
        }
        while(cnt--) ans.push_back(0);
        nums = ans;
    }
};