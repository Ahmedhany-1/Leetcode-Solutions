class Solution {
public:
    vector<int> minOperations(string boxes) {
        int total_sum = 0 , total_n = 0;
        for(int i = 0 ; i < boxes.size() ; ++i){
            if(boxes[i] == '1'){
                total_sum += i;
                total_n++;
            }
        }

        int cur_sum = total_sum , cur_n = total_n;
        vector<int> ans(boxes.size() , 0);
        for(int i = 0 ; i < boxes.size(); ++i){
            ans[i] += abs((total_sum - cur_sum) - i * (total_n - cur_n));
            if(boxes[i] == '1') cur_sum -= i , cur_n--;
            ans[i] += (cur_sum - i * cur_n);
            // if() // skip prev if first 1
        }
        return ans;
    }
};