class Solution {
public:
    unordered_map<string, int> dp;
    int helper(vector<int> &nums, int target, int n, int ind, int val) {
        if(ind == n && val == target) return 1;
        if(ind == n) return 0;

        string str = to_string(val) + ":" + to_string(ind);
        if(dp.find(str)!=dp.end()) return dp[str];

        int pos = helper(nums, target, n, ind+1, val+nums[ind]);
        int neg = helper(nums, target, n, ind+1, val-nums[ind]);

        return dp[str] = pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return helper(nums, target, n, 0, 0);
    }
};
