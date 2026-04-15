class Solution {
public:
    int helper(vector<int> & prices, int n, int ind, bool buy, vector<vector<int>> &dp) {
        if(ind >= n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy) {
            int take = helper(prices, n, ind+1, false, dp) - prices[ind];
            int skip = helper(prices, n, ind+1, true, dp);
            profit = max(max(take, skip), profit);
        } else {
            int sell = helper(prices, n, ind+2, true, dp) + prices[ind];
            int skip = helper(prices, n, ind+1, false, dp);
            profit = max(max(sell, skip), profit);
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));

        return helper(prices, n, 0, true, dp);
    }
};