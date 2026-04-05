class Solution {
public: 
    bool helper(vector<int>& nums, int n, int ind, vector<vector<int>> &dp, int target) {
        if(target == 0) return dp[ind][target] = true;
        if(ind == n || target<0) return false;
        if(dp[ind][target] != -1) return dp[ind][target];

        return dp[ind][target] = helper(nums, n, ind+1, dp, target-nums[ind]) ||
                            helper(nums, n, ind+1, dp, target);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto i: nums) {
            sum+=i;
        }

        if(sum%2 == 1) return false;
        vector<vector<int>> dp(n+1, vector<int>(sum/2+1, -1));
        return helper(nums, n, 0, dp, sum/2);
    }
};
