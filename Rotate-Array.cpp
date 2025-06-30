class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> dq(nums.begin(), nums.end());
        k %= nums.size();
        while(k--) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
        nums.assign(dq.begin(), dq.end()); // Copy deque back to vector
    }
};