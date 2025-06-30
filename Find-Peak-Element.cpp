class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0 , r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l + 1) / 2;
            if(nums[mid] > nums[mid - 1]) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};

/*

int n = nums.size();
        for(int i = 0; i < n - 1; ++i){
            if(nums[i] > nums[i + 1]) 
                return i;
        }
        
        return n - 1;

here the first indx may be the answer if num[i] > num[i + 1] so it will be answer
if not so i will be next so move till find nums[i] > nums[i + 1]
*/