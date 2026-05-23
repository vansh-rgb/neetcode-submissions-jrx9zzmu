class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st1;
        stack<pair<int,int>> st2;

        int area = heights[0];
        int maxArea = area;

        st1.push(make_pair(heights[0],0));

        for(int i=1;i<heights.size();i++) {
            maxArea = max(maxArea, heights[i]);
            int minInd = i;
            while(!st1.empty() && st1.top().first>heights[i]) {
                maxArea = max(maxArea, st1.top().first*(i-st1.top().second));
                minInd = min(minInd,st1.top().second);
                st1.pop();
            }
            while(!st1.empty() && heights[i]>=st1.top().first) {
                int ind = st1.top().second;
                int val = st1.top().first;
                maxArea = max(maxArea, val*(i-ind+1));
                st1.pop();
                st2.push(make_pair(val,ind));
            }
            while(!st2.empty()) {
                int ind = st2.top().second;
                int val = st2.top().first;
                st2.pop();
                st1.push(make_pair(val, ind));
            }
            st1.push(make_pair(heights[i],minInd));
        }
        int n = heights.size();
        while(!st1.empty()) {
            maxArea = max(maxArea, st1.top().first*(n-st1.top().second));
            st1.pop();
        }
        return maxArea;
    }
};