class Solution {
    bool valid(const vector<int>& bloomDay, int m, int k, int needed_days) {
        int flowers = 0, bouquets = 0;
        for (int day : bloomDay) {
            if (day <= needed_days)
                ++flowers;
            else
                flowers = 0;

            if (flowers == k) {
                ++bouquets;
                flowers = 0;
                if (bouquets >= m) return true; // early exit
            }
        }
        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > bloomDay.size()) return -1;

        int left = 1, right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(bloomDay, m, k, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left; // or right; both are same here
    }
};
