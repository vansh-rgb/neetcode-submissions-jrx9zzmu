class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        for(int i=0;i<nums.size();i++) {
            if(maxJump<i) break;
            if(i+nums[i] > maxJump) {
                maxJump = i+nums[i];
            }
            if(maxJump >= nums.size()-1) return true;
        }
        return false;
    }
};
