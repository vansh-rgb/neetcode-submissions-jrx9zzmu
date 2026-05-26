class Solution {
public:
    unordered_map<int,int> m;
    int helper(int n, vector<int> nums, int start) {
        if(n<start) return 0;
        if(m.count(n)) return m[n];

        int oneSkip = helper(n-2, nums, start) + nums[n];
        int twoSkip = helper(n-3, nums, start) + nums[n];

        return m[n] = max(oneSkip, twoSkip);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int res1 = max(helper(nums.size()-2, nums, 0), helper(nums.size()-3, nums, 0));
        m.clear();
        int res2 = max(helper(nums.size()-1, nums, 1), helper(nums.size()-2, nums, 1));
        return max(res1, res2);
    
    }
};
