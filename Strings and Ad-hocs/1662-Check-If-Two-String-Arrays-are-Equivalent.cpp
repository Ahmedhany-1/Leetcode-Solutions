class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a,b; 
        for(auto &s : word1){
            for(auto &c : s)
                a.push_back(c);
        }

        for(auto &s : word2){
            for(auto &c : s)
                b.push_back(c);
        }
        if(a.size() != b.size()) return false;
        for(int i = 0 ; i < (int)a.size() ; ++i){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};