class Solution {
public:
    int countPalindromicSubsequence_v1(string s) {
       int n = s.size();
       int last_idx[26]{} , freq[26]{} , ans = 0;
       for(int i = 0 ; i < n ; ++i){
            freq[s[i] - 'a']++;
            last_idx[s[i] - 'a'] = i;
       }
       bool take[26]{};
       for(int i = 0 ; i < n ; ++i){
            if(freq[s[i] - 'a'] > 1 && !take[s[i] - 'a']){
                take[s[i] - 'a'] = 1;
                set<char> st;
                for(int j = i + 1 ; j < last_idx[s[i] - 'a'] ; ++j) 
                    st.insert(s[j]);
                ans += st.size();
            }
       }
       return ans;
    }

    int countPalindromicSubsequence(string s) {
        bitset<26> exist;
        int ans = 0;
        for(int i = 0; i < 26; i++){
            int l = s.find('a' + i);
            if(l != string::npos){
                int r = s.find_last_of('a' + i);
                if(r - l < 2) continue;
                for(int k = l + 1; k < r; k++){
                    exist.set(s[k] -'a');
                    if(exist.count() == 26) break;
                }
                ans += exist.count();
                exist.reset();
            }
        }
        return ans;
    }
};

/*
bbcbaba

char   last idx       freq    take or not
b          5           4          1
c          2           1
a          6           2          1

if(freq[char] > 1 && !take)
	ans += all uniqe char between first and last 

b = 5 - 0 - 1 - 1 = 3
a = 6 - 4 - 1 - 0 = 1

*/