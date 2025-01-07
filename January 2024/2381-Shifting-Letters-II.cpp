class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> pref(n + 1, 0);
        for (auto& it : shifts) {
            int st = it[0], en = it[1], di = it[2];
            pref[st] += (di == 0 ? -1 : 1);
            pref[en + 1] += (di == 0 ? 1 : -1);
        }
        for (int i = 1; i < n; i++) pref[i] += pref[i - 1];
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = pref[i] % 26;
            s[i] = 'a' + (s[i] - 'a' + cur + 26) % 26; 
        }
        return s;
    }
};
