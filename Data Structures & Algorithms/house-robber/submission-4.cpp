class Solution {
public:
    unordered_map<int,int> m;
    int helper(int n, vector<int> nums) {
        if(n<0) return 0;
        if(m.count(n)) return m[n];

        int oneSkip = helper(n-2, nums) + nums[n];
        int twoSkip = helper(n-3, nums) + nums[n];

        return m[n] = max(oneSkip, twoSkip);
    }

    int rob(vector<int>& nums) {
        return max(helper(nums.size()-1, nums), helper(nums.size()-2, nums));
    }
};
