class Solution {
public:
    int possibleStringCount(string word) {
        int cnt = 0;
        for(int i = 1; i < word.size(); ++i){
            cnt += word[i] == word[i - 1];
        }
        return cnt + 1;
    }
};