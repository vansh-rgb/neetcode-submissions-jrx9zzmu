class Solution {
   public:
    int helper(int amount, vector<int>& coins, int ind, int n, vector<vector<int>>& dp) {

        if (amount == 0) return 1;
        if (ind == n || amount < 0) return 0;
        if (dp[ind][amount] != -1) return dp[ind][amount];

        int take = (coins[ind] <= amount)
                ? helper(amount - coins[ind], coins, ind, n, dp)
                : 0;
        int skip = helper(amount, coins, ind+1, n, dp);
        return dp[ind][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return helper(amount, coins, 0, n, dp);
    }
};
