class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int osum = INT_MIN;
        int sum = 0;
        for(auto i: nums) {
            if(sum < 0) {
                sum = 0;
            }
            sum+=i;
            osum = max(osum, sum);
        }
        return osum;
    }
};
