class Solution {
public:
    vector<string> findAndReplacePattern_1(vector<string>& words,string pattern) {
        set<char> st1, st2;
        vector<string> ans;
        for (auto& it : pattern)
            st1.insert(it);
        for (auto& word : words) {
            for (auto& ch : word) {
                st2.insert(ch);
            }
            if (st1.size() == st2.size())
                ans.push_back(word);
            st2.clear();
        }

        // part 2 check pattern
        map<char, int> mp_pattern;
        for (auto& it : pattern)
            mp_pattern[it]++;
        for (auto& word : words) {
            bool f = 1;
            for (int i = 0; i < word.size(); ++i) {
                if (mp_pattern.count(word[i]) != mp_pattern.count(pattern[i])) {
                    f = 0;
                    break;
                }
            }
        }

        return ans;
    }

    // part 2 : check the pattern match the word
    bool check(string &pattern , string &word){
        unordered_map<char, char> mp_P;  
        unordered_map<char, char> mp_W;  

        for (int i = 0; i < word.size(); ++i) {
            char w = word[i], p = pattern[i];
            
            if (mp_W.count(w) && mp_W[w] != p) return false;
            if (mp_P.count(p) && mp_P[p] != w) return false;
            
            mp_W[w] = p;
            mp_P[p] = w;
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto &word : words) {
            if (check(word, pattern)) {
                ans.push_back(word);
            }
        }
        return ans;
    }

};

/*
abc                         abb      
unorderes_freq[{a,a} , {b,b}]         unorderes_freq[{a,a} , {b,b} , ]

deq                         abb      
unorderes_freq[1,2]         unorderes_freq[1,2]

mee                         abb      
unorderes_freq[1,2]         unorderes_freq[1,2]
*/