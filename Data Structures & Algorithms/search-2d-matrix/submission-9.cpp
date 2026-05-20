class Solution {
public:
    int helper(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size()-1;

        while(low<high) {
            int mid = low + (high-low+1)/2;

            if(matrix[mid][0] > target) {
                high = mid-1;
            } else {
                low = mid;
            }
        }
        return low;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int getRow = helper(matrix, target);

        int low = 0;
        int high = matrix[0].size()-1;

        while(low<high) {
            int mid = low + (high-low)/2;

            if(matrix[getRow][mid] == target) return true;
            if(matrix[getRow][mid] > target) {
                high  = mid-1;
            }else low = mid+1;
        }
        return matrix[getRow][low] == target;
    }
};
