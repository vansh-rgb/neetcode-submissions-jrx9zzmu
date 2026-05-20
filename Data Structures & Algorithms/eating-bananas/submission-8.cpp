class Solution {
public:
    int helper(vector<int> &piles, int h, int mid) {
        int count = 0;
        for(auto &i: piles) {
            if(mid>i) {
                count++;
                continue;
            } else {
                if(i%mid == 0)
                    count+=(i/mid);
                else count+=((i/mid) + 1);
            }
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2; 
            if (helper(piles, h, mid) <= h)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
