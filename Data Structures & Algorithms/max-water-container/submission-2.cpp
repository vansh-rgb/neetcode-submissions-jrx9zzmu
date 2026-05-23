class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int area = 0;
        while(l<r) {
            if(heights[l]<=heights[r]) {
                area = max(area, heights[l]*(r-l));
                l++;
            } else {
                area = max(area, heights[r]*(r-l));
                r--;
            }
        }
        return area;
    }
};
