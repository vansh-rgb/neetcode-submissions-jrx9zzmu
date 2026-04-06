class Solution {
public:
    unordered_map<int,int> m;
    int helper(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(amount<0) return INT_MAX;

        if(m.find(amount) != m.end()) return m[amount];

        int res = INT_MAX-1;
        for(auto &i: coins) {
            if(i<=amount) {
                res  = min(res, helper(coins, amount-i)+1);
            }
        }

        return m[amount] = res;

    }
    int coinChange(vector<int>& coins, int amount) {
        int res = helper(coins, amount);
        if(res == INT_MAX-1) return -1;
        return res;
    }
};
