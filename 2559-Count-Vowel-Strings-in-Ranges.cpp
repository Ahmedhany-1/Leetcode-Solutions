class Solution {
public:
    bool is_vowel(char &c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n, 0) , ret;
        for (int i = 0; i < n ; ++i) {
            if(is_vowel(words[i].front()) && is_vowel(words[i].back()))
                pref[i] = 1;
            else
                pref[i] = 0;
        }
        for(int i = 1 ; i < n ; ++i) pref[i] += pref[i - 1];
        // ["aba","bcb","ece","aa","e"]  [1 , 1 , 2, 3, 4]
    
        for(auto &it : queries){
            int l = it[0] , r = it.back();
            if(l == 0) ret.push_back(pref[r]);
            else ret.push_back(pref[r] - pref[l - 1]);
        }
        return ret;
    }
};