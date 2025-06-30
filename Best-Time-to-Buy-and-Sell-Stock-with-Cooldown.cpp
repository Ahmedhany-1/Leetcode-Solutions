class Solution {
    vector<vector<int>> mem;
public:
    int maxProfit(vector<int>& prices) {
        mem.resize(prices.size(), vector<int>(2, -1));
        return solve(0, 0, prices);  
    }

    // status: 0 = not holding (can buy), 1 = holding (can sell)
    int solve(int i, int holding, vector<int>& prices){
        if(i >= prices.size())
            return 0;

        auto &ret = mem[i][holding];
        if(ret != -1) return ret;

        int op1 = solve(i + 1, holding, prices); // skip
        int op2 = 0;

        if(holding)
            // sell and cooldown next day
            op2 = prices[i] + solve(i + 2, 0, prices);
        else
            // buy
            op2 = -prices[i] + solve(i + 1, 1, prices);

        return ret = max(op1, op2);
    }
};
