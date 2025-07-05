class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int res = 0;
        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (it != heaters.end()) ? abs(house - *it) : INT_MAX;
            int dist2 = (it != heaters.begin()) ? abs(house - *(it - 1)) : INT_MAX;
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};
