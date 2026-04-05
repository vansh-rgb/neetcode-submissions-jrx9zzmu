class Solution {
public:
    int helper(vector<int>& nums, int n, vector<vector<int>> &dp, int ind, int prev) {
        if(ind == n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int take = 0;
        if(prev == -1 || nums[prev]<nums[ind]) {
            take = helper(nums, n, dp, ind+1, ind) + 1;
        }

        int skip = helper(nums, n, dp, ind+1, prev);
        return dp[ind][prev+1] = max(take, skip);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1, -1));

        return helper(nums, n, dp, 0, -1);
    }
};
