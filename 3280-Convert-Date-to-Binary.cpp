class Solution {
    string ans = "";
    void toBinary(int x){
        while(x){
            if(x & 1) ans = '1' + ans;
            else ans = '0' + ans;
            x >>= 1;
        }
    }
public:
    string convertDateToBinary(string date) {
        int year = 0 , month = 0 , day = 0;
        year = stoi(date.substr(0 , 4));
        month = stoi(date.substr(5 , 2));
        day = stoi(date.substr(8 , 2));

        toBinary(day);
        ans = '-' + ans;
        toBinary(month);
        ans = '-' + ans;
        toBinary(year);
       
        return ans;
    }
};