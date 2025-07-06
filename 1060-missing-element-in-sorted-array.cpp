class Solution {
public:
	// Return how many numbers are missing until nums[idx]
	int missing(int idx, vector<int> &nums) {
		return nums[idx] - nums[0] - idx;
	}
	// Using idx, what is kth missing number
	int kth(int idx, vector<int> &nums, int k) {
		// k - missing(idx, nums) = the remaining values
		return nums[idx] + k - missing(idx, nums);
	}

	int missingElement(vector<int> &nums, int k) {
		int n = nums.size();
		// kth missing number after last number?
		if (k > missing(n - 1, nums))
			return kth(n - 1, nums, k);

		int start = 0, end = n - 1;
		// find the first idx where missing(idx) >= k
		while (start < end) {
			int mid = start + (end - start) / 2;

			if (missing(mid, nums) < k)
				start = mid + 1;
			else
				end = mid;
		}
		// Use the previous idx (end - 1) to find the missing element
		return kth(end - 1, nums, k);
	}
};

/*
 int missingElement_v1(vector<int> &nums, int k) {
        int idx = 0, st = nums[0], ans = -1;
        while(k){
            if(idx < nums.size() && nums[idx] == st){
                idx++, st++;
                continue;
            }
            k--;
            ans = st++;
        }
        return ans;
    }
*/
