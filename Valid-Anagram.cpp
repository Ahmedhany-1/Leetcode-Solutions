class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        int freq_s[26]{};

        for(auto &i : s) freq_s[i - 'a']++;

        for(int i = 0; i < t.size(); ++i){
            int idx = t[i] - 'a';
            --freq_s[idx];
            if(freq_s[idx] < 0) return false;
        }
        return true;
        
    }
};