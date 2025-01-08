class Solution {
public:
    int dp[5000][2];
    int solve(int idx, bool have_stock, vector<int>& prices) {
        // base case
        if (idx >= prices.size()) return 0;
        if(dp[idx][have_stock] != -1) return dp[idx][have_stock];

        int op1 = 0 , op2 = 0; 
        if (!have_stock) {
            op1 = solve(idx + 1, true, prices) - prices[idx]; // buy
        }
        if(have_stock)  op2 = solve(idx + 2, false, prices) + prices[idx]; // sell

        int op3 = solve(idx + 1, have_stock, prices); //nothing

        return dp[idx][have_stock] = max({op1, op2 , op3});
    }
    int maxProfit(vector<int>& prices) {
        memset(dp , -1 , sizeof dp);
       int x = solve(0 , 0 , prices) ;
       return x;
    }
};