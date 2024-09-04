class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //O(log(m*n))=O(logM +logN)
        int rows=matrix.size();
        int cols=matrix[0].size();
        int left=0,right=rows*cols-1,mid;
        int row,col;
        while(left<=right){
            mid=(left+right)/2; //index if we flatten the 2d array t be 1D
            row=mid/cols;
            col=mid%cols;
            if(matrix[row][col]<target)
                left=mid+1;
            else if(matrix[row][col]>target)
                right=mid-1;
            else
                return true;
        }
        return false;
    }
};