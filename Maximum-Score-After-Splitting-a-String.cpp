class Solution {
public:
    int maxScore(string s) {
        int n = s.size() , ans = 0;
        int zero = 0 , ones = count(s.begin() , s.end() , '1');
        for(int i = 0 ; i < n - 1 ; i++){
            if(s[i] == '1') ones--;
            else zero++;
            ans = max(ans , ones + zero);
        }
        return ans;
    }
};

/*
"00111" cnt = 1
[3,3,2,1,0]

"011101"
[1,1,1,0,1,0]
[4,3,2,1,1,0]
*/