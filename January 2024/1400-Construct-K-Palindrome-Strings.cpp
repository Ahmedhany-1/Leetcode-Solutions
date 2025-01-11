class Solution {
public:
    bool canConstruct(string s, int k) {
        int arr[26]{} , cnt{};
        if(k > s.size()) return 0;
        for(auto &it : s) arr[it - 'a']++;  
        for(int i = 0 ; i < 26 ; i++) cnt += (arr[i] & 1);
        return (cnt <= k);
    }
};