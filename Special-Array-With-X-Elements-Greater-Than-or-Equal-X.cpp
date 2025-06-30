class Solution {
public:
    int specialArray(vector<int>& nums) {
        int N = nums.size();
        
        vector<int> freq(N + 1, 0);
        for (int i = 0; i < N; i++) {
            freq[min(N, nums[i])]++;
        }
        
        int numGreaterThanOrEqual = 0;
        for (int i = N; i >= 1; i--) {
            numGreaterThanOrEqual += freq[i];
            if (i == numGreaterThanOrEqual) {
                return i;
            }
        }
        
        return -1;
    }
};







/*
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
       for (int x = 1; x <= n; ++x) { 
            // how many elements are >= x
            int count = n - (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
            if (count == x) return x; 
        }
        return -1;
    }
       
};
*/




/*
nums = [0, 4, 3, 10]
nums[0] = 0: freq[min(4, 0)]++ → freq[0]++ → freq = [1, 0, 0, 0, 0].
nums[1] = 4: freq[min(4, 4)]++ → freq[4]++ → freq = [1, 0, 0, 0, 1].
nums[2] = 3: freq[min(4, 3)]++ → freq[3]++ → freq = [1, 0, 0, 1, 1].
nums[3] = 10: freq[min(4, 10)]++ → freq[4]++ → freq = [1, 0, 0, 1, 2].

*/






// 0 1 2 3 4 5
//[1,1,1,3,4,5]
// [> , > , > , true , <] number of elements >= x is >



/*
 int specialArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 1 ; i <= n ; ++i){
            int cnt = 0;
            for(int j = 0 ; j < n ; ++j){
                if(nums[j] >= i) cnt++;
                if(cnt > i) break;
            }
            if(cnt == i) return i;
        }
        return -1;
    }
*/