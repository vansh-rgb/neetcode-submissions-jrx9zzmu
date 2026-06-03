class Solution {
public:
    int checkHours(int mid, vector<int> &piles) {
        int count = 0;
        for(auto i: piles) {
            if(i%mid == 0) count+=(i/mid);
            else count+=(i/mid)+1;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mid = 0;
        while(low<high) {
            mid = low+(high-low)/2;

            if(checkHours(mid, piles) <= h) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        return high;
    }
};
