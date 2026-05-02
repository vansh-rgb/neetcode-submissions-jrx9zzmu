class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX-1);
        int n = nums.size();
        dp[0] = 0;
        for(int i=0;i<nums.size();i++) {
            int t = nums[i];
            while(t>0) {
                if(i+t<n && dp[i]!=INT_MAX) {
                    dp[i+t] = min(dp[i]+1, dp[i+t]);
                }
                t--;
            }
        }
        return dp[n-1];
    }
};
