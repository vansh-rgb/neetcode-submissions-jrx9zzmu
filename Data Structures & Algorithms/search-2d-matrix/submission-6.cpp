class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto getRow = [&](auto &&self) -> int {
            int low = 0;
            int high = matrix.size()-1;
            int mid;
            while(low<high) {
                mid = low+(high-low+1)/2;
                if(matrix[mid][0] <= target) {
                    low = mid;
                } else {
                    high = mid-1;
                }
            }
            return low;
        };
        int row = getRow(getRow);
        auto search = [&](auto &&self) -> bool {
            int low = 0;
            int high = matrix[0].size()-1;
            int mid;
            while(low<=high) {
                mid = low+(high-low)/2;
                if(matrix[row][mid] < target) {
                    low = mid+1;
                } else if(matrix[row][mid] > target) {
                    high = mid-1;
                } else return true;
            }
            return false;
        };
        return search(search);
    }
};
