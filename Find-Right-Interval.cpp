class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> st; // (start, index)

        for (int i = 0; i < n; ++i)
            st.emplace_back(intervals[i][0], i);

        sort(st.begin(), st.end());

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int end = intervals[i][1];
            int idx = lower_bound(st.begin(), st.end(), make_pair(end, 0)) - st.begin();
            if (idx == n)
                ans[i] = -1;
            else
                ans[i] = st[idx].second;
        }
        return ans;
    }
};
