class Solution {
public:
    bool isPalindrome(string s) {
        string news;
        for(auto &it : s) {
            if(isalpha(it)) news += tolower(it);
            if(isdigit(it)) news += it;
        }
        int n = news.size();
        for(int i = 0 ; i < n; ++i){
            if(news[i] != news[n - i - 1]) return false;
        }        
        return true;
    }   
};